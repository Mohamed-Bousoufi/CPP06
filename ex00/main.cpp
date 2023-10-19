#include<iostream>

#include "ScalarConverter.hpp"


std :: string ScalarConverter :: _parameter;
int main(int argc ,char **argv)
{
    if(argc == 2)
    { 
        ScalarConverter Sc(argv[1]);
        Sc.parser();
        Sc.convert();
    }
    else
    std :: cout << "Parameters Not Correct " << std :: endl;
}