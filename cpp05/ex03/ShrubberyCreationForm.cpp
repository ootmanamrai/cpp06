#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other) , _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if(this != &other)
        _target = other._target;
    return(*this);
}

void ShrubberyCreationForm::executed(Bureaucrat const &executor) const{
    std::string name = this->_target + "_shrubbery";
    std::ofstream outfile(name.c_str());
    if(outfile.is_open())
    {
        outfile << "         /\\\n";
        outfile << "        /  \\\n";
        outfile << "       /    \\\n";
        outfile << "      /      \\\n";
        outfile << "     /________\\\n";
        outfile << "       /\\  /\\\n";
        outfile << "      /  \\/  \\\n";
        outfile << "     /        \\\n";
        outfile << "    /__________\\\n";
        outfile << "        ||||\n";
        outfile << "        ||||\n";
        outfile.close();
    }
}