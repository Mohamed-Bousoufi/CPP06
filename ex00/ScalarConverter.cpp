#include "ScalarConverter.hpp"

ScalarConverter ::ScalarConverter(const char *string)
{
	this->_parameter = string;
}

ScalarConverter ::ScalarConverter(std ::string &parameter)
{
	this->_parameter = parameter;
}

ScalarConverter ::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

void ScalarConverter ::operator=(const ScalarConverter &copy)
{

	this->_parameter = copy._parameter;
}

ScalarConverter ::~ScalarConverter()
{
}

void ScalarConverter::parser(std :: string str)
{
	try
	{
		size_t index;
		index = _parameter.find_first_not_of(" \t\n\r");
		ScalarConverter ::_parameter = &_parameter[index];
		int points = 0;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '.')
				points++;
		}
	if (points > 1)
		throw "Invalide Parameter !!!";
	}
	catch (const char *e)
	{
		std::cout << e << std ::endl;
		exit(1);
	}
}

void ScalarConverter ::Intprint()
{
	std ::cout << "int : ";
	try
	{
		if(_parameter.empty())
			throw "impossible";
		size_t digit = 0;
		for (size_t i = 0; i < _parameter.length(); i++)
		{
			if (!std ::isdigit(_parameter[i]))
				digit++;
		}
		if ((_parameter[0] == '-' || _parameter[0] == '+'  ) && digit < _parameter.length())
		{
			digit--;
		}
		if (digit == _parameter.length() && _parameter.length() > 1)
		{
			throw "impossible";
		}
		else if (digit == 2 && _parameter.back() == 'f' && _parameter.find('.') != std ::string ::npos)
		{
			double f = std ::atof(_parameter.c_str());
			if (f >= (static_cast<double>(INT_MAX) + 1) || f < (static_cast<double>(INT_MIN)))
			{
				throw "impossible";
			}
			int number = static_cast<int>(f);
			std ::cout << number << std ::endl;
			return;
		}
		else if (digit == 0)
		{
			double f = std ::atof(_parameter.c_str());
			if (f >= (static_cast<double>(INT_MAX) + 1) || f < (static_cast<double>(INT_MIN)))
			{
				throw "impossible";
			}
			int number = static_cast<int>(f);
			std ::cout << number << std ::endl;
			return;
		}
		else if (digit == _parameter.length() == 1)
		{
			int number = static_cast<int>(_parameter[0]);
			std ::cout << number << std ::endl;
			return;
		}
		else if (digit == 1 && _parameter.find('.') != std ::string ::npos)
		{
			double f = std ::atof(_parameter.c_str());
			if (f >= (static_cast<double>(INT_MAX) + 1) || f < (static_cast<double>(INT_MIN)))
			{
				throw "impossible";
			}
			int number =static_cast<int>(f);
			std ::cout << number << std ::endl;
			return;
		}
		else
			throw "impossible";
	}
	catch (const char *e)
	{
		std::cout << e << std ::endl;
	}
}

void ::ScalarConverter ::Floatprint()
{
	std ::cout << "float : ";
	try
	{
		if(_parameter.empty())
			throw "impossible";
		size_t digit = 0;
		for (size_t i = 0; i < _parameter.length(); i++)
		{
			if (!std ::isdigit(_parameter[i]))
				digit++;
		}
		if ((_parameter[0] == '-' || _parameter[0] == '+'  ) && digit < _parameter.length())
		{
			digit--;
		}
		if (digit == _parameter.length() && _parameter.length() > 1)
		{
			if (!_parameter.compare("nanf") || !_parameter.compare("nan"))
				throw "nanf";
			else if (!_parameter.compare("-inff") || !_parameter.compare("-inf"))
				throw "-inff";
			else if (!_parameter.compare("+inff") ||  !_parameter.compare("+inf"))
				throw "+inff";
			else
				throw "impossible";
		}
		else if (digit == 2 && _parameter.back() == 'f' && _parameter.find('.') != std ::string ::npos)
		{
			double f = std ::atof(_parameter.c_str());
			if (f >= (static_cast<double>(__FLT_MAX__) + 1))
			{
				throw "impossible";
			}
			float number = static_cast<float>(f);
			std ::cout << std::fixed << std::setprecision(1) << number << "f" << std ::endl;
			return;
		}
		else if (digit == 0)
		{
			double f = std ::atof(_parameter.c_str());
			if (f >= (static_cast<double>(__FLT_MAX__) + 1))
			{
				throw "impossible";
			}
			float number = static_cast<float>(f);
			std ::cout << std::fixed << std::setprecision(1) << number << "f" << std ::endl;
			return;
		}
		else if (digit == _parameter.length() == 1)
		{
			float number = static_cast<float>(_parameter[0]);
			std ::cout << std::fixed << std::setprecision(1) << number << std ::endl;
			return;
		}
		else if (digit == 1 && _parameter.find('.') != std ::string ::npos)
		{
			double f = std ::atof(_parameter.c_str());
			if (f >= (static_cast<double>(__FLT_MAX__) + 1))
			{
				throw "impossible";
			}
			float number = std ::stof(_parameter);
			std ::cout << std::fixed << std::setprecision(1) << number << "f" << std ::endl;
			return;
		}
		else
			throw "impossible";
	}
	catch (const char *e)
	{
		std::cout << e << std ::endl;
	}
}

void ScalarConverter ::Doubleprint()
{
	std ::cout << "Double : ";

	try
	{
		if(_parameter.empty())
			throw "impossible";
		size_t digit = 0;
		for (size_t i = 0; i < _parameter.length(); i++)
		{
			if (!std ::isdigit(_parameter[i]))
				digit++;
		}
		if ((_parameter[0] == '-' || _parameter[0] == '+'  ) && digit < _parameter.length())
		{
			digit--;
		}
		if (digit == _parameter.length() && _parameter.length() > 1)
		{
			if (!_parameter.compare("nanf") || !_parameter.compare("nan"))
				throw "nan";
			else if (!_parameter.compare("-inff") || !_parameter.compare("-inf"))
				throw "-inf";
			else if (!_parameter.compare("+inff") || !_parameter.compare("+inf"))
				throw "+inf";
			else
				throw "impossible";
		}
		else if (digit == 2 && _parameter.back() == 'f' && _parameter.find('.') != std ::string ::npos)
		{
			if (_parameter.length() >= 308)
				throw "impossible";
			double number = std ::atof(_parameter.c_str());
			std ::cout << std::fixed << std::setprecision(1) << number << std ::endl;
			return;
		}
		else if (digit == 0)
		{
			if (_parameter.length() >= 308)
				throw "impossible";
			double number = std ::atof(_parameter.c_str());
			std ::cout << std::fixed << std::setprecision(1) << number << std ::endl;
			return;
		}
		else if (digit == _parameter.length() == 1)
		{
			double number = static_cast<double>(_parameter[0]);
			std ::cout << std::fixed << std::setprecision(1) << number << std ::endl;
			return;
		}
		else if (digit == 1 && _parameter.find('.') != std ::string ::npos)
		{
			if (_parameter.length() >= 308)
				throw "impossible";
			double number = std ::atof(_parameter.c_str());
			std ::cout << std::fixed << std::setprecision(1) << number << std ::endl;
			return;
		}
		else
			throw "impossible";
	}
	catch (const char *e)
	{
		std::cout << e << std ::endl;
	}
}

void ScalarConverter ::Charprint()
{
	std :: cout << "char : ";
	try
	{
		if(_parameter.empty())
			throw "impossible";
		size_t digit = 0;
		for (size_t i = 0; i < _parameter.length(); i++)
		{
			if (!std ::isdigit(_parameter[i]))
				digit++;
		}
		if ((_parameter[0] == '-' || _parameter[0] == '+'  ) && digit < _parameter.length())
		{
			digit--;
		}
		if (digit == _parameter.length() && _parameter.length() > 1)
		{
				throw "impossible";
		}
		else if (digit == 2 && _parameter.back() == 'f' && _parameter.find('.') != std ::string ::npos)
		{
			double number = std ::atof(_parameter.c_str());
			if(number > 31 && number <= 126)
			{
				char c = static_cast<char>(number);
				std :: cout <<"'"<<c<<"'"<< std :: endl;
				return;
			}
			else
				throw "Non displayable";
			
		}
		else if (digit == 0)
		{
			double number = std ::atof(_parameter.c_str());
			if(number > 31 && number <= 126)
			{
				char c = static_cast<char>(number);
				std :: cout <<"'"<<c<<"'"<< std :: endl;
				return;
			}
			else
				throw "Non displayable";
		}
		else if (digit == _parameter.length() == 1)
		{
			std :: cout <<"'"<<_parameter <<"'"<< std :: endl;
		}
		else if (digit == 1 && _parameter.find('.') != std ::string ::npos)
		{
			double number = std ::atof(_parameter.c_str());
			if(number > 31 && number <= 126)
			{
				char c = static_cast<char>(number);
				std :: cout <<"'"<<c<<"'"<< std :: endl;
				return;
			}
			else
				throw "Non displayable";
		}
		else
			throw "impossible";

	}
	catch (const char *e)
	{
		std::cout << e << std ::endl;
	}
}

void ScalarConverter :: convert(std :: string str)
{
	parser(str);
	Charprint();
	Intprint();
	Floatprint();
	Doubleprint();
}
