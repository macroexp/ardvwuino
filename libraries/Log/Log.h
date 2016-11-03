#ifndef _LOG_H_
#define _LOG_H_

#define BUFSIZE 32*8

class Log {
	private:
		char buffer[BUFSIZE];
		unsigned int buflast;
		IWire *output;
	public:
		Log(IWire* output);
		void println(const char* msg);
#ifdef ARDUINO
		void println(String msg);
#endif
		void sendLog();
};

#endif