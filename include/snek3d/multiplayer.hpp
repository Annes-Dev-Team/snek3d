#include <cstddef>
#include <enet/enet.h>
#include <iostream>
#include <vector>

namespace Snek3D {
    namespace Multiplayer {
        inline void DUMMY(ENetEvent* event) {}
        struct Client {
            ENetHost* host = nullptr;
            ENetPeer* peer = nullptr;
            ENetEvent event{};
            ENetAddress address{};

            bool connect(const std::string& ip, int port) {

                host = enet_host_create(nullptr, 1, 2, 0, 0);

                if (!host) {
                    return false;
                }

                enet_address_set_host(&address, ip.c_str());
                address.port = port;

                peer = enet_host_connect(host, &address, 2, 0);

                if (!peer) {
                    return false;
                }

                return true;
            }

            void send(const std::string& text) {
                ENetPacket* packet = enet_packet_create(
                    text.c_str(),
                    text.size() + 1,
                    ENET_PACKET_FLAG_RELIABLE
                );

                enet_peer_send(peer, 0, packet);
            }

            void disconnect() {
                if (peer) {
                    enet_peer_disconnect(peer, 0);
                }
            }

            std::string get_ip() {
                char ip[32];
                enet_address_get_host_ip(&address, ip, sizeof(ip));
                return std::string(ip);
            }

            int get_port() {
                return address.port;
            }
            void run(int mili=10) {

                while (enet_host_service(host, &event, mili) > 0) {

                    switch (event.type) {

                        case ENET_EVENT_TYPE_CONNECT:
                            std::cout << "Connected to server\n";
                            break;

                        case ENET_EVENT_TYPE_RECEIVE:

                            std::cout
                                << "Server says: "
                                << (char*)event.packet->data
                                << std::endl;

                            enet_packet_destroy(event.packet);

                            break;

                        case ENET_EVENT_TYPE_DISCONNECT:
                            std::cout << "Disconnected\n";
                            break;

                        default:
                            break;
                    }
                }
            }
        };

        struct Server {
            ENetAddress address = {};
            ENetHost* server = nullptr;
            ENetEvent event = {};
            std::vector<Client> clients={};

            void init(int port=2556,size_t max_clients=32);
            void run(int mili=10);
            int lookup_client_index(Client* client);

            void (*connect_condition)(ENetEvent* evet) = DUMMY;
            void (*receive_condition)(ENetEvent* evet)= DUMMY;
            void (*disconnect_condition)(ENetEvent* evet) = DUMMY;
        };

    }
}
