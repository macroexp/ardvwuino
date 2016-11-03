class WireWrapper : public IWire {
	public:
		unsigned long write(const char *str){
			Wire.write(str);
		}
		unsigned long write(int value){
			Wire.write(value);
		}
};