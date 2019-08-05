/*
 * Author: pedrito.
 * Date: 05/08/19
*/

#ifndef SERVER_ANNOUNCEMENT_H
#define SERVER_ANNOUNCEMENT_H

#include <Event.h>
#include <server_packets/ExSay.h>

class Announcement : public Event {
	public:
		explicit Announcement(size_t interval = 1000) : Event(interval)
		{
		}

	public:
		/*
 		 * Called each $interval seconds
		 * call stop() to end the interval
		 */
		void run() override
		{
			Server::broadcast(new ExSay("Hello World"));
			// stop()
		}

		void stop() override
		{
			Event::stop();
			// do aditionnal stuff here if needed
		}
};

#endif //SERVER_ANNOUNCEMENT_H
