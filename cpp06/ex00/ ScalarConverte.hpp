#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define RED "\033[31m"
#include <string>
#include <iomanip>
#include <unistd.h>
#include <iostream>
#include <limits>
#include <float.h>
class ScalarConverte {
    public :
    ScalarConverte();
    ~ScalarConverte();
    ScalarConverte(const ScalarConverte &other);
    ScalarConverte &operator=(const ScalarConverte &other);
    static void convert(const std::string& str);
};
#endif 