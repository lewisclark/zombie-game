#include "logger.h"

game::Logger::Logger(const std::string& filename) {
	m_ofstream = std::ofstream(filename, std::ios_base::app);
}

void game::Logger::LogString(const std::string& s) {
	m_ofstream << s;
	m_ofstream.flush();
}

std::unique_ptr<game::Logger> game::logger = nullptr;
