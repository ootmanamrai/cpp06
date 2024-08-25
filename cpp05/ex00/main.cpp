#include "Bureaucrat.hpp"

int main()
{
    try
    {
    Bureaucrat b("rh", 1);
    std::cout << b;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "catch exception:" << e.what() << std::endl;
    }
}