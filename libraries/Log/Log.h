#define BUFSIZE 32*8

class Log {
	private:
		char buffer[BUFSIZE];
		unsigned int buflast;
	public:
		Log();
		void println(const char* msg);
		void println(String msg);
		void sendLog();
};