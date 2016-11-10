#ifndef _LOG_H_
#define _LOG_H_

#ifndef ARDUINO
	typedef unsigned int byte;
#endif

#define BUFSIZE 32*8

class Log {
	private:
		char buffer[BUFSIZE];
		byte head, tail;
		IWire *output;
	public:
		Log(IWire* output);
		void println(const char* msg);
		//void diags();
		//void print(const char* msg);
#ifdef ARDUINO
		void println(String msg);
#endif
		void sendLog();
	private:
		byte min(byte a, byte b);
};



#endif