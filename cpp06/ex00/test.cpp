#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cfloat>
#include <cmath>
#include <cstring>

class ScalarConverter {
public:
    static void convert(const std::string& literal) {
        if (isCharLiteral(literal)) {
            char c = literal[1];
            printResults(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
        } else if (isIntLiteral(literal)) {
            long l = std::strtol(literal.c_str(), NULL, 10);
            if (errno == ERANGE || l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max()) {
                std::cout << "int: impossible" << std::endl;
            } else {
                int i = static_cast<int>(l);
                printResults(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
            }
        } else if (isFloatLiteral(literal)) {
            float f = std::strtof(literal.c_str(), NULL);
            if (errno == ERANGE || f < -FLT_MAX || f > FLT_MAX) {
                std::cout << "float: impossible" << std::endl;
            } else {
                printResults(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
            }
        } else if (isDoubleLiteral(literal)) {
            double d = std::strtod(literal.c_str(), NULL);
            if (errno == ERANGE || d < -DBL_MAX || d > DBL_MAX) {
                std::cout << "double: impossible" << std::endl;
            } else {
                printResults(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
            }
        } else {
            std::cout << "Error: Literal type not recognized." << std::endl;
        }
    }

private:
    static bool isCharLiteral(const std::string& literal) {
        return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
    }

    static bool isIntLiteral(const std::string& literal) {
        char* endptr;
        std::strtol(literal.c_str(), &endptr, 10);
        return *endptr == '\0';
    }

    static bool isFloatLiteral(const std::string& literal) {
        if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
        char* endptr;
        std::strtof(literal.c_str(), &endptr);
        return *endptr == 'f' && *(endptr + 1) == '\0';
    }

    static bool isDoubleLiteral(const std::string& literal) {
        if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;
        char* endptr;
        std::strtod(literal.c_str(), &endptr);
        return *endptr == '\0';
    }

    static void printResults(char c, int i, float f, double d) {
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }

        std::cout << "int: " << i << std::endl;

        if (std::isnan(f) || std::isinf(f) || (f > -FLT_MAX && f < FLT_MAX)) {
            std::cout << "float: " << f << "f" << std::endl;
        } else {
            std::cout << "float: impossible" << std::endl;
        }

        if (std::isnan(d) || std::isinf(d) || (d > -DBL_MAX && d < DBL_MAX)) {
            std::cout << "double: " << d << std::endl;
        } else {
            std::cout << "double: impossible" << std::endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}
