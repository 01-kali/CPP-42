#include <Serializer.hpp>

int main(){

	Data *data = new Data;
	data->i = 10;

	std::cout << "data->i: "<< data->i << std::endl;
	
  uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << "serialized->i: " << serialized->i << std::endl;

	delete data;
	return 0;
}
