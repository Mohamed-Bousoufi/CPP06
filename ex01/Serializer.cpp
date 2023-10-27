#include "Serializer.hpp"


Data *Serializer :: _ptr;

Serializer ::Serializer()
{
	_ptr = NULL;
}

Serializer ::Serializer(Data *ptr)
{
	this->_ptr = ptr;
}

Serializer ::Serializer(Serializer &copy)
{
		*this = copy;
}

Serializer &Serializer ::operator=(Serializer &copy)
{
	this->_ptr = copy._ptr;
	return (*this);
}

Serializer :: ~Serializer()
{

}

uintptr_t Serializer :: serialize(Data *ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return(raw);
}

Data * Serializer :: deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);

	return(ptr);
}