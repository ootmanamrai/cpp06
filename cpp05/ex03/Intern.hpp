#ifndef INTERN_HPP
#define INTERN_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;
class Intern {
    public :
    Intern();
    ~Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    Form *makeForm(std::string Formname, std::string Targetform);

};
#endif