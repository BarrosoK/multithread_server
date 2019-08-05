/*
 * Author: pedrito.
 * Date: 05/08/19
*/

#ifndef SERVER_ANNOUNCEMENT_H
#define SERVER_ANNOUNCEMENT_H

#include <Event.h>

class Announcement : public Event {
	public:
		explicit Announcement(size_t interval = 1000) : Event(interval)
		{
		}

	public:
		/*
 		 * Called each 60 seconds
		 * call stop() to end the interval
		 */
		void run() override
		{
			std::cout << "test" << std::endl;
			// Server::broadcast(new Ex...)
			// stop()
		}

		void stop() override
		{
			Event::stop();
			// do aditionnal stuff here if needed
		}
};

#endif //SERVER_ANNOUNCEMENT_H
