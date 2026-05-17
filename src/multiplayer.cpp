#include "snek3d/multiplayer.hpp"
#include "enet/enet.h"
#include <cstddef>
#include <cstdio>
#include <iostream>

void Snek3D::Multiplayer::Server::init(int port, size_t max_clients) {
    address.host = ENET_HOST_ANY;
    address.port = port;
    server = enet_host_create(&address, max_clients, 2, 0, 0);
    if (!server) {
        std::cerr << "Error creating server " << server;
    }
}

void Snek3D::Multiplayer::Server::run(int mili) {
    while (enet_host_service(server, &event, mili) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT: {
                std::cout << "New client " << event.peer->address.host << ":" << event.peer->address.port;
                clients.push_back({event.peer});
                connect_condition(&event);
                break;
            }

            case ENET_EVENT_TYPE_NONE: {
                break;
            }
            case ENET_EVENT_TYPE_DISCONNECT: {
                
                break;
            }
            case ENET_EVENT_TYPE_RECEIVE:  {break;}
            
        }
    }
}

int Snek3D::Multiplayer::Server::lookup_client_index(Client* client) {
    for (size_t i = 0; i < clients.size(); i++) {
        Client* meow = &clients[i];
        if (meow->client->address.host == client->client->address.host) {
            return i;
        }
    }
    return -1;
}
