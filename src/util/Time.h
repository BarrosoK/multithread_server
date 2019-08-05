/*
 * Author: pedrito.
 * Date: 05/08/19
*/

#ifndef SERVER_TIME_H
#define SERVER_TIME_H

#include <string>
#include <sstream>
#include <ctime>
#include <iostream>

class Time {
	public:
		static const std::string getTime() {
			std::ostringstream ss;
			std::time_t t = std::time(0);
			std::tm *now = std::localtime(&t);
			ss << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec;
			return ss.str();
		}
		static const std::string getDate(std::string separator = "/") {
			std::ostringstream ss;
			std::time_t t = std::time(0);
			std::tm *now = std::localtime(&t);
			ss << now->tm_mday << separator << now->tm_mon << separator << (now->tm_year + 1900);
			return ss.str();
		}
};

#endif //SERVER_TIME_H
