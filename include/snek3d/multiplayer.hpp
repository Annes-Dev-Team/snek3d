#include <cstddef>
#include <enet/enet.h>
#include <vector>

namespace Snek3D {
    namespace Multiplayer {
        inline void DUMMY(ENetEvent* event) {}
        struct Client {
            ENetPeer *client = nullptr;
            ENetEvent event;
            ENetAddress address;
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
