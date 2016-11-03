#include "IWire.h"

class CoutWrapper : public IWire {
	public:
		unsigned long write(const char *str);
		unsigned long write(int value);
};