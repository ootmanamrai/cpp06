#include " ScalarConverte.hpp"

int main(int ac, char **av)
{
    
    if(ac == 2)
    {
        if(!*av[1])
            std::cout << RED "Error The argument should not be empty\n" RESET;
        else
            ScalarConverte::convert(av[1]);

    }
    else
        std::cout << RED "Error argument, Usage : ./convert <literal>\n" RESET;
}