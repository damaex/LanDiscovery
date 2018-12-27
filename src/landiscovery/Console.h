#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <exception>

#ifdef _WIN32
#define NEWLINE "\r\n"
#elif defined macintosh // OS 9
#define NEWLINE "\r"
#else
#define NEWLINE "\n" // Unix & Mac OS X uses \n
#endif

class Console {
private:
	static std::string getNewLine() {
		return NEWLINE;
	}

public:
	static void writeLine(const std::string &text) {
		Console::write(text + Console::getNewLine());
	}

	static void write(const std::string &text) {
		std::cout << text;
	}

	static void exception(const std::exception &ex) {
		Console::write("Exception: ");
		Console::writeLine(ex.what());
	}

	static std::string readLine() {
		std::string in;
		std::cin >> in;

		return in;
	}
};

#endif //CONSOLE_H