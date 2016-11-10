class WireWrapper : public IWire {
	public:
		size_t write(const char *str){
			return Wire.write(str);
		}
		size_t write(int value){
			return Wire.write(value);
		}
		size_t write(const char *buffer, size_t size){
			return Wire.write((const uint8_t *)buffer, size);
		}
};