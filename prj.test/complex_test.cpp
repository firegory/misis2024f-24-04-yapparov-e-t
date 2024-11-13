#include<complex/complex.hpp>

#include <iostream>

void testOperations(const Complex& n, const Complex& n1)
{
    std::cout << "\n";
    std::cout << n << " + " << n1 << " = " << (n + n1) << "\n";
    std::cout << n << " - " << n1 << " = " << (n - n1) << "\n";
    std::cout << n << " * " << n1 << " = " << (n * n1) << "\n";
    std::cout << n << " / " << n1 << " = " << (n / n1) << "\n";
    std::cout << "-" << n << " = " << -n << "\n";
    std::cout << "-" << n1 << " = " << -n1 << "\n";
    if (n == n1)
    {
        std::cout << n << " = " << n1 << "\n";
    }
    else
    {
        std::cout << n << " != " << n1 << "\n";
    }
}
void testOperationsWithNumber(const Complex& n, const double& n1)
{
    std::cout << "\n";
    std::cout << n << " + " << n1 << " = " << (n + n1) << "\n";
    std::cout << n1 << " + " << n << " = " << (n1 + n) << "\n";
    std::cout << n << " - " << n1 << " = " << (n - n1) << "\n";
    std::cout << n1 << " - " << n << " = " << (n1 - n) << "\n";
    std::cout << n << " * " << n1 << " = " << (n * n1) << "\n";
    std::cout << n1 << " * " << n << " = " << (n1 * n) << "\n";
    std::cout << n << " / " << n1 << " = " << (n / n1) << "\n";
    std::cout << n1 << " / " << n << " = " << (n1 / n) << "\n";
    if (n == n1)
    {
        std::cout << n << " = " << n1 << "\n";
    }
    else
    {
        std::cout << n << " != " << n1 << "\n";
    }
    if (n1 == n)
    {
        std::cout << n1 << " = " << n << "\n";
    }
    else
    {
        std::cout << n1 << " != " << n << "\n";
    }
}


int main()
{
    Complex n(1, 1);
    Complex n1(2, 1);

    testOperations(n, n1);
    testOperationsWithNumber(n, 2);

    Complex n0(0, 0);

    std::cout << "\n" << n << " / " << n0 << " = ";
    try
    {
        std::cout << (n / n0) << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n" << n << " / " << 0 << " = ";
    try
    {
        std::cout << (n / 0) << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }

    /*std::string tempStr;
    std::cout << "The numbers should be inputed in format {R;I}, where R is a real part of the number and I is the imaginary part\n";

    std::cout << "\nInput the first number: ";
    std::cin >> tempStr;
    while (!testOutput(tempStr))
    {
        std::cout << "\nInput the first number again: ";
        std::cin >> tempStr;
    }
    std::istringstream istrm(tempStr);
    istrm >> n;

    std::cout << "\nInput the second number: ";
    std::cin >> tempStr;
    while (!testOutput(tempStr))
    {
        std::cout << "\nInput the second number again: ";
        std::cin >> tempStr;
    }
    istrm = std::istringstream(tempStr);
    istrm >> n1;

    testOperations(n, n1);

    double r = 0;
    std::cout << "\nInput a real number: ";
    std::cin >> r;
    testOperationsWithNumber(n, r);*/
}
