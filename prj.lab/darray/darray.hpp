#include <iosfwd>
#include<sstream>

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
    Darray(const Darray& obj) = default;

    Darray& operator=(const Darray&) = default;

    int length();
    
    void append(const double value);
    double& operator[](const int ind);

    ~Darray();

};



#endif // !Darray_HPP