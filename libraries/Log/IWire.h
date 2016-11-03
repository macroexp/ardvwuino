#ifndef _IWIRE_H_
#define _IWIRE_H_

class IWire {
	public:
		virtual unsigned long write(const char *str) = 0;
		virtual unsigned long write(int value) = 0;
};

#endif