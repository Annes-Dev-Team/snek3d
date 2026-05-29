#include <chrono>
#include <cstring>
#include <iostream>
#include <snek3d/multiplayer.hpp>
#include <thread>

int main(int argc, char** argv) {
    std::cout << argc << std::endl;
    if (argc >= 2) {
        if (std::strcmp(argv[1], "server") == 0) {
            Snek3D::Multiplayer::Server server;
            std::cout << "server\n";
            server.init();
            while (true) {
                server.run();
            }
        } else {
            Snek3D::Multiplayer::Client client;
            client.connect("127.0.0.1", 25565);
            std::cout << "client\n";
            while (true) {
                client.run();
                client.send("Meow");
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
        return 1;
    }
}
