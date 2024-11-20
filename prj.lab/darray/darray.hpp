#include <iosfwd>
#include<sstream>
#include <stdarg.h>
#include<initializer_list>

#ifndef Darray_HPP
#define Darray_HPP

class Darray
{
private:
    int len = 0;
    int allocatedMemory = 8;
    double* startAdress;

    static const char sep = '/';
public:
    Darray();
    explicit Darray(const int length);
    Darray(const std::initializer_list<double> array);
    Darray(const Darray& obj);

    Darray& operator=(const Darray& rhs);

    int length();
    
    void append(const double value);
    double& operator[](const int ind);

    ~Darray();

};



#endif // !Darray_HPP