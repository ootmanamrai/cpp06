#include <iostream>
#include "Bureaucrat.hpp"
#ifndef FORM_HPP
#define FORM_HPP
class Bureaucrat;
class Form{
private :
    const std::string  _name;
    bool _signed;
    const int _gradeTosign;
    const int _gradeToexecute;
    Form();
public :
    Form(const Form &other);
    Form(const std::string &name , int gradetosingn);
    ~Form();
    Form &operator=(const Form &other);
    const std::string getname() const;
    bool getsigned() const;
    const int getgradetosign() const;
    const int getgradetoexecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    //exception class
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Form &ob);
#endif