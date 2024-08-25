#include <iostream>
#include <cstdlib>  // For std::strtod

int convertToInt(const std::string& str) {
    // Convert the string to a double
    char* end;
    double num = std::strtod(str.c_str(), &end);

    // If the conversion was successful (end points to the end of the string)
    if (*end == '\0' || (*end == 'f' && *(end + 1) == '\0')) {
        // Cast the double to an int (truncates the fractional part)
        return static_cast<int>(num);
    } else {
        // Handle error: the string contains invalid characters
        std::cerr << "Conversion error: the string contains invalid characters." << std::endl;
        return 0;  // Or any other error value or handling mechanism
    }
}

int main() {
    std::string str1 = "43.f";
    std::string str2 = "-42.5";
    std::string str3 = "4.0";
    std::string str4 = "123";
    std::string str5 = "not a number";

    std::cout << "Converted value of " << str1 << ": " << convertToInt(str1) << std::endl;
    std::cout << "Converted value of " << str2 << ": " << convertToInt(str2) << std::endl;
    std::cout << "Converted value of " << str3 << ": " << convertToInt(str3) << std::endl;
    std::cout << "Converted value of " << str4 << ": " << convertToInt(str4) << std::endl;
    std::cout << "Converted value of " << str5 << ": " << convertToInt(str5) << std::endl;

    return 0;
}
