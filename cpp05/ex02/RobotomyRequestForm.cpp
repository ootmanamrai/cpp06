#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm" , 72, 45) , _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form(other) , _target(other._target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
        _target = other._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){}

void RobotomyRequestForm::executed(Bureaucrat const &executor) const
{
    std::cout << "hahaha drilling noises ppppppp \n";
    static int i;
    if(i % 2 == 0)
    {
        std::cout << this->_target << " successfully robotomized!" << std::endl;
    i++;
    }
    else
    {
        std::cout <<  this->_target << " Robotomy failed !" << std::endl;
        i++;
    }
}