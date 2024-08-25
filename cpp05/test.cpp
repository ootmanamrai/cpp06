#include <iostream>

class Example
{
public:
    int value;

    // Constructor
    Example(int v) : value(v) {}

    // Copy Assignment Operator
    Example &operator=(const Example &other)
    {
        if (this == &other)
            return *this; // Check for self-assignment

        // value = other.value;
        std::cout << "Copy assignment operator called\n";
        return *this;
    }

    void print() const
    {
        std::cout << "Value: " << value << std::endl;
    }
};

int main()
{
    Example obj1(10); // Normal constructor
    Example obj2(20); // Normal constructor
    obj2 = obj1;      // Copy assignment operator invoked

    obj1.print();
    obj2.print();

    return 0;
}
