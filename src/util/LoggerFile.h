/*
 * Author: pedrito.
 * Date: 05/08/19
*/

#ifndef SERVER_LOGGERFILE_H
#define SERVER_LOGGERFILE_H

#include <fstream>
#include "Time.h"

class LoggerFile {
	private:
		std::ofstream file;
	public:
		LoggerFile(const std::string &fileName = "log")
		{
			file.open(fileName + "-" + Time::getDate(":"));
			file.seekp(std::ios::beg);
			if (file.good()) {
				file << "=== LOG ===" << std::endl;
				file << Time::getDate() << " " << Time::getTime() << std::endl;
				file.flush();
			}
		}

		virtual ~LoggerFile()
		{
			if (!file.good())
				return;
			file << std::endl << "======" << std::endl << "    End   Output log ( "
				<< Time::getDate() << " at " << Time::getTime() << " ): ";
			file.flush();
			file.close();
		}

		void write() {}
		template<typename T, typename ...Args>
		void write(T first, Args ...arg)
		{
			file << first;
			file.flush();
			write(arg ...);
		}

};

#endif //SERVER_LOGGERFILE_H
