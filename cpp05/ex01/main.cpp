#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
    Bureaucrat b("rh", 1);
    Form form("Form1" , 10);
    b.signForm(form);
    std::cout << form;
    }
    catch (const std::exception &e)
    {
        std::cout << "catch exception:" << e.what() << std::endl;
    }
}
