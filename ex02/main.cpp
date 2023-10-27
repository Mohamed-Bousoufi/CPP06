#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{        
    Base *base = generate();
    identify(base);
    identify(*base);
}