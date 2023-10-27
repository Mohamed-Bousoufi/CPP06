#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <ctime>
#include<iostream>

Base * generate(void)
{
    time_t t;

    time(&t);
    if(t % 2 == 0)
        return (new A());
    else if(t % 3 == 0)
        return(new B());
    else
        return(new C());
}

void identify(Base* p)
{
    A *pa;
    B *pb;
    C *pc;

    pa = dynamic_cast<A *>(p);
    pb = dynamic_cast<B *>(p);
    pc = dynamic_cast<C *>(p);
    if(pa)
    {
        std :: cout << "the actual type of the object pointed is A" << std :: endl;
        return;
    }
    else if(pb)
    {
        std :: cout << "the actual type of the object pointed is B" << std :: endl;
        return;
    }
    else if(pc)
    {
        std :: cout << "the actual type of the object pointed is C" << std :: endl;
        return;
    }
    else
        std :: cout << "Can't identify the actual type of the object pointed" << std :: endl;


}

void identify(Base& p)
{

    try
    {
       (void)dynamic_cast<A &>(p);

        std :: cout << "the actual type of the object pointed is A" << std :: endl;
        return;
    }
    catch(std :: bad_cast a)
    {
        try
        {
            (void)dynamic_cast<B &>(p);
                std :: cout << "the actual type of the object pointed is B" << std :: endl;
                return;
        }
        catch(std :: bad_cast b) 
        {
            try
            {
                (void)dynamic_cast<C &>(p);

                    std :: cout << "the actual type of the object pointed is C" << std :: endl;
                    return;
            }
            catch(std :: bad_cast c) 
            {
                std :: cout << "Can't identify the actual type of the object pointed" << std :: endl;
            }
        }
    }
}