/*
 * Author: pedrito.
 * Date: 05/08/19
*/

#ifndef SERVER_ANNOUNCEMENTS_H
#define SERVER_ANNOUNCEMENTS_H

#include <iostream>
#include <thread>
#include <zconf.h>
#include <functional>
#include <future>
#include <atomic>

template<class F, class... Args>
void setInterval(std::atomic_bool &cancelToken, size_t interval, F &&f, Args &&... args)
{
	cancelToken.store(true);
	auto cb = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
	std::async(std::launch::async, [=, &cancelToken]()mutable {
		while (cancelToken.load()) {
			cb();
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
		}
	});
}

class Event {
	private:
		std::atomic_bool b;
		size_t interval;

	public:
		explicit Event(size_t interval = 1000) : interval(interval)
		{
			std::thread *handler = new std::thread(&Event::init, this);
		}

		virtual void init()
		{
			setInterval(b, interval, &Event::run, this);
		}

		virtual void run() = 0;

		virtual void stop()
		{
			b.store(false);
		}

		virtual void start()
		{
			b.store(true);
		}
};

#endif //SERVER_ANNOUNCEMENTS_H
