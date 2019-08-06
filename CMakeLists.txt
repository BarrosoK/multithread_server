cmake_minimum_required(VERSION 3.13)
project(server)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc src/network src/util)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(MySQL REQUIRED)
find_package(MySQLPP REQUIRED)
find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${MYSQL_INCLUDE_DIRS} ${MYSQLPP_INCLUDE_DIR})


set(project_ui src/ui/ServerUi.ui)
set(project_headers inc/ui/ServerUi.h)

qt5_wrap_ui(ui_wrap ${project_ui})
qt5_wrap_cpp(moc_sources ${project_headers})

add_executable(server main.cpp
        src/Server.cpp
        inc/Server.h
        src/Client.cpp
        inc/Client.h
        src/handlers/ClientHandler.cpp
        src/network/ReceivablePacket.cpp
        inc/ReceivablePacket.h
        src/network/SendablePacket.cpp
        inc/SendablePacket.h
        src/handlers/PacketHandler.cpp
        src/network/client_packets/RequestOther.h
        src/network/server_packets/ExOther.h
        src/network/server_packets/ExDisconnect.h
        src/network/server_packets/ExClient.h
        src/network/server_packets/ExConnection.h
        src/network/client_packets/RequestDate.h
        src/network/client_packets/RequestTime.h
        src/network/server_packets/ExSay.h
        src/network/server_packets/ExDate.h
        src/network/server_packets/ExKick.h
        src/network/server_packets/ExTime.h
        src/util/LoggerFile.h src/util/Time.h
        inc/Event.h src/events/Announcement.h
        client_test.cpp src/DatabasePool.cpp
        inc/DatabasePool.h inc/Singleton.h
        src/ui/ServerUi.cpp inc/ui/ServerUi.h
        ${ui_wrap} ${moc_sources} inc/ui/ListItem.h)
target_link_libraries(server Threads::Threads)
target_link_libraries(server ${MYSQL_LIBRARIES})
target_link_libraries(server ${mysqlpp_LIBRARY})
target_link_libraries(server
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)
