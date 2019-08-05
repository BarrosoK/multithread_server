cmake_minimum_required(VERSION 3.13)
project(server)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc src/network src/util)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_executable(server main.cpp src/Server.cpp inc/Server.h src/Client.cpp inc/Client.h src/handlers/ClientHandler.cpp src/network/ReceivablePacket.cpp inc/ReceivablePacket.h src/network/SendablePacket.cpp inc/SendablePacket.h src/handlers/PacketHandler.cpp src/network/client_packets/RequestLogin.h src/network/client_packets/RequestMove.h
        src/network/server_packets/ExLogin.h
        src/network/server_packets/ExConnection.h
        src/network/client_packets/RequestDate.h
        src/network/server_packets/ExSay.h
        src/network/server_packets/ExDate.h
        src/network/server_packets/ExMove.h
        src/util/LoggerFile.h src/util/Time.h
        inc/Event.h src/events/Announcement.h
        client_test.cpp)
target_link_libraries(server Threads::Threads)


