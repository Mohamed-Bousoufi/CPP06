
#include "Serializer.hpp"


int main()
{
    Data dt;

    dt.str = "value";
    dt.value = 1445;

    Serializer Sz(&dt);

    std :: cout << &dt << std :: endl;
    uintptr_t key =  Sz.serialize(&dt);
    std :: cout <<std :: hex << "0x" << key << std :: endl;
    std :: cout << (Sz.deserialize(key)) << std :: endl;
    std :: cout << "string : "<<(Sz.deserialize(key))->str << " || value : " <<std :: dec<<(Sz.deserialize(key))->value << std :: endl;


}