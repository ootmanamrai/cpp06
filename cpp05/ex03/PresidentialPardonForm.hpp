#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"
class PresidentialPardonForm : public Form {
private :
    std::string _target;
    PresidentialPardonForm();
public :
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    void executed(Bureaucrat const &executor) const;

};
#endif