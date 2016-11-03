class WireWrapper : public IWire {
	public:
		unsigned long write(const char *str){
			return Wire.write(str);
		}
		unsigned long write(int value){
			return Wire.write(value);
		}
};