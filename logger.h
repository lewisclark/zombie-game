#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <fstream>

#include "include/fmtlib/format.h"

namespace game {
	class Logger {
		public:
		Logger(const std::string& filename);

		void LogString(const std::string& s);

		template <typename... Args>
		void LogFormat(const std::string& fmt, const Args&... args) {
			LogString(fmt::format(fmt.c_str(), args...));
		}

		private:
		std::ofstream m_ofstream;
	};

	extern std::unique_ptr<Logger> logger;
}

#endif
