#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"

class ShrubberyCreationForm  : public  Form {
private :
     std::string _target;
     ShrubberyCreationForm(void);
public :
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    void executed(Bureaucrat const &executor) const;
};

#endif