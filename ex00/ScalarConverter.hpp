#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include<sstream>
#include<string.h>
#include <iomanip>
#include <limits>
class ScalarConverter
{
    private :

    static std :: string _parameter;

    public : 
            ScalarConverter();
            ScalarConverter(std :: string &parameter);
            ScalarConverter(const char * string);
            ScalarConverter(const ScalarConverter &copy);
            void operator =(const ScalarConverter &copy);
            ~ScalarConverter();
        
            static void Intprint();
            static void Floatprint();
            static void Charprint();
            static void Doubleprint();
            static void parser();
            static void convert();
        
};
#endif