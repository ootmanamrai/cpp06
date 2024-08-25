#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5) , _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other) , _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if(this != &other)
        _target = other._target;
    return(*this);
}

void PresidentialPardonForm::executed(Bureaucrat const &executor) const
{
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
