#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data
{
    int value;
    std :: string str;
};

class Serializer 
{
    private :
    static Data * _ptr;

    public :

    Serializer();
    Serializer(Data *ptr);
    Serializer(Serializer &copy);
    Serializer & operator = (Serializer &copy);
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data * deserialize(uintptr_t raw);
};
#endif