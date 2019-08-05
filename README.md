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


## Usage

There are a couple shared run configurations for IntelliJ.

There is also a client function which is REALLY basic and hardcoded. I would recommend you to create your own client aside in order to develop efficiently
    
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[GPL](https://github.com/BarrosoK/multithread_server/blob/master/LICENSE)
