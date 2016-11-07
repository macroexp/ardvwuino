#ifndef _IWIRE_H_
#define _IWIRE_H_

class IWire {
	public:
		virtual size_t write(const char *str) = 0;
		virtual size_t write(int value) = 0;
		virtual size_t write(const char *buffer, size_t size) = 0;
};

#endif