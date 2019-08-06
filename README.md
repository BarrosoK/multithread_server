# MultiThread Server

Feel free to use this server as skeleton for your own project.


Here's the 3 important classes to see in order to create your own protocol


| Class        | Description           | 
| ------------- |:-------------:| 
|   [SendablePacket](https://github.com/BarrosoK/multithread_server/blob/master/src/network/SendablePacket.cpp)       | Packets sent to the client | 
|   [ReceivablePacket](https://github.com/BarrosoK/multithread_server/blob/master/src/network/ReceivablePacket.cpp)       | Packets received to the client | 
|   [PacketHandler](https://github.com/BarrosoK/multithread_server/blob/master/src/handlers/PacketHandler.cpp)       | Received packet distribution, you can add here your own packets | 
| [Event](https://github.com/BarrosoK/multithread_server/blob/master/inc/Event.h) | Used to call a runnable class with interval [(example)](https://github.com/BarrosoK/multithread_server/blob/master/src/events/Announcement.h) |


You can use already existing [packets examples](https://github.com/BarrosoK/multithread_server/blob/master/src/network/client_packets/RequestLogin.h) to understand how it work


## Installation

* Clone the project
* Open it with IntelliJ IDEA
* You're ready to code !

#### MySQL

Install the MySQL server by using the Ubuntu package manager:


```
sudo apt-get update
sudo apt-get install mysql-server
```

After installation is complete, the mysql_secure_installation utility runs. This utility prompts you to define the mysql root password and other security related options, including removing remote access to the root user and setting the root password.

##### Start the MySQL service

```bash
systemctl start mysql
```

##### Launch at reboot

```bash
systemctl enable mysql
```

#### MySQL Driver connector

Install the MySQL drivers by using the ubuntu package manager: 

```bash
sudo apt-get install libmysqlcppconn-dev
```

Or manually [here](https://dev.mysql.com/downloads/connector/cpp/)

#### QT5

```bash
sudo apt-get install build-essential qtcreator
```

If you want QT5 to be your default version you can aswell run this command
```bash
sudo apt-get install qt5-default
```

## Usage

There are a couple shared run configurations for IntelliJ.

There is also a client function which is REALLY basic and hardcoded. I would recommend you to create your own client aside in order to develop efficiently

A more advanced (but still basic and for test purpose only) is available [here](https://github.com/BarrosoK/client)
    
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[GPL](https://github.com/BarrosoK/multithread_server/blob/master/LICENSE)
