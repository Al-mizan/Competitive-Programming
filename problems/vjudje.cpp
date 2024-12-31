#include <iostream>
#include <iomanip>

int main() {
    double num1 = 1234.12347887;
    double num2 = 12.12349898;
    double num3 = 12.12;
    double num4 = -45.1234;

    // Set precision to 4 decimal places and total width to 9 (including the negative sign)
    std::cout << std::fixed << std::setprecision(4);

    // Format each number with width 9, padding with zeros
    std::cout << std::setw(9) << std::setfill('0') << num1 << std::endl;
    std::cout << std::setw(9) << std::setfill('0') << num2 << std::endl;
    std::cout << std::setw(9) << std::setfill('0') << num3 << std::endl;
    std::cout << std::setw(9) << std::setfill('0') << num4 << std::endl;

    return 0;
}
