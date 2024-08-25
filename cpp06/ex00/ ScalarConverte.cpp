#include " ScalarConverte.hpp"

ScalarConverte::ScalarConverte(){
    std::cout << BLUE  "ScalarConverte Default Constructor Called\n" RESET;
}

ScalarConverte::~ScalarConverte(){
    std::cout << BLUE "ScalarConverte Destructor Called\n" RESET;
}

ScalarConverte &ScalarConverte::operator=(const ScalarConverte &other){
    std::cout << BLUE "ScalarConverte Copy assigment operator Called\n" RESET;
    return (*this);
}

ScalarConverte::ScalarConverte(const ScalarConverte &other){
    std::cout << BLUE "ScalarConverte copy constructor called\n" RESET;
}

bool check_input(const std::string &str)
{
    if (str == "-inff" || str == "-inf")
    {
        std::cout << RED << "Char   : Impossible" << RESET << std::endl;
        std::cout << RED << "int    : Impossible" << RESET << std::endl;
		std::cout << BLUE << "float  : " << "-inff" << RESET << std::endl;
        std::cout << BLUE << "double : " << "-inf" << RESET << std::endl;
        return(true);
    }
	else if (str == "+inff" || str == "+inf")
    {
        std::cout << RED << "Char   : Impossible" << RESET << std::endl;
        std::cout << RED << "int    : Impossible" << RESET << std::endl;
		std::cout << BLUE << "float  : " << "+inff" << std::endl;
        std::cout << BLUE << "double : " << "+inf" << RESET << std::endl;
        return(true);
    }
	else if (str == "nanf" || str == "nan")
    {
        std::cout << RED << "Char   : Impossible" << RESET << std::endl;
        std::cout << RED << "int    : Impossible" << RESET << std::endl;
		std::cout << BLUE << "float  : " << "nanf" << RESET << std::endl;
        std::cout << BLUE << "double : " << "nan" << RESET << std::endl; 
        return(true);      
    }
    return(false);
}

void ischar(const std::string &str)
{
    if(str.size() == 1)
    {
        char value = static_cast<char>(str[0]);
        if(std::isdigit(value) || !std::isprint(value))
            std::cout << RED  "char : Non displayable\n"  RESET;
        else
            std::cout << BLUE "char : '" << value << "'\n" RESET;
    }
    else
    {
    char* end;
    long  num = std::strtod(str.c_str(), &end);
    char convert = static_cast<char>(num);
    if(num < 0  || num > 255 || *end != '\0')
        std::cout << RED "char : Impossible\n" RESET;
    else if(!std::isprint(convert))
        std::cout << RED "char : Non displayable\n" RESET;
    else
        std::cout << BLUE "char : '" << convert << "'\n"; 
    }
}

void isint(const std::string &str)
{
    char* end;
    long long  num = std::strtod(str.c_str(), &end);
    if (*end == '\0' || (*end == 'f' && *(end + 1) == '\0'))
    {
        if(num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
            std::cout << RED "int : Impossible \n" RESET;
        else
            std::cout << BLUE "int : " << static_cast<int>(num)  << std::endl << RESET ;
    }
    else
        std::cout << RED "int : Impossible \n" RESET;
}

void isdouble(const std::string &str)
{
    char* end;
    double num = std::strtod(str.c_str(), &end);
    if (*end == '\0' || (*end == 'f' && *(end + 1) == '\0'))
    {
        if (num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max())
            std::cout << RED "double : Impossible\n" RESET;
        else if(str.find('.') == std::string::npos)
            std::cout << BLUE "double : " << static_cast<double>(num)  << ".0" <<  std::endl << RESET;
        else
            std::cout << BLUE "double : " << static_cast<double>(num) << std::endl << RESET;
    }
    else
        std::cout << RED "double : Impossible\n" RESET;
}

void isfloat(const std::string &str)
{
    char *end;
    double num = strtof(str.c_str(), &end);
    if (*end == '\0' || (*end == 'f' && *(end + 1) == '\0'))
    {
        std::string convert = std::to_string(num);
        if(num < -FLT_MAX || num > FLT_MAX)
            std::cout << RED "float : Impossible\n" RESET;
        else if(str.find('.') == std::string::npos)
            std::cout << BLUE "float : " << std::fixed << std::setprecision(1) << convert <<  ".0f" <<  std::endl << RESET;
        else 
            std::cout << BLUE "float : " << convert  << "f" <<  std::endl << RESET;
    }
    else
        std::cout << RED "float : Impossible\n" BLUE;
}

void ScalarConverte::convert(const std::string &str)
{
    if(!check_input(str))
    {
    ischar(str);
    isint(str);
    isfloat(str);
    isdouble(str);
    }
}

