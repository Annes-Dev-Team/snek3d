#include "snek3d/multiplayer.hpp"
#include "enet/enet.h"
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <algorithm>

void Snek3D::Multiplayer::Server::init(int port, size_t max_clients) {
    address.host = ENET_HOST_ANY;
    address.port = port;
    server = enet_host_create(&address, max_clients, 2, 0, 0);
    if (!server) {
        std::cerr << "Error creating server " << server << std::endl;
    }
}

void Snek3D::Multiplayer::Server::run(int mili) {
    while (enet_host_service(server, &event, mili) > 0) {
        std::cout << event.type << std::endl;

        switch (event.type) {

            case ENET_EVENT_TYPE_CONNECT: {

                Client client;

                client.peer = event.peer;
                client.address = event.peer->address;

                clients.push_back(client);

                std::cout << "New client "
                    << clients.back().get_ip()
                    << ":"
                    << clients.back().get_port()
                    << std::endl;

                connect_condition(&event);

                break;
            }

            case ENET_EVENT_TYPE_NONE: {
                break;
            }

            case ENET_EVENT_TYPE_DISCONNECT: {
                std::cout << "Client disconnected\n";

                // remove client from vector
                clients.erase(
                    std::remove_if(
                        clients.begin(),
                        clients.end(),
                        [&](const Client& c) {
                            return c.peer == event.peer;
                        }
                    ),
                    clients.end()
                );

                break;
            }

            case ENET_EVENT_TYPE_RECEIVE: {
                std::cout << "Received packet: "
                          << (char*)event.packet->data
                          << std::endl;

                // IMPORTANT
                enet_packet_destroy(event.packet);

                break;
            }
        }
    }
}

int Snek3D::Multiplayer::Server::lookup_client_index(Client* client) {
    for (size_t i = 0; i < clients.size(); i++) {
        Client* meow = &clients[i];
        if (meow->peer->address.host == client->peer->address.host) {
            return i;
        }
    }
    return -1;
}
