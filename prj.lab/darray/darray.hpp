#include <iosfwd>
#include<sstream>
#include <stdarg.h>
#include<initializer_list>

#ifndef Darray_HPP
#define Darray_HPP

class Darray
{
private:
    ptrdiff_t len = 0;
    ptrdiff_t allocatedMemory = 8;
    double* startAdress;

    static const char sep = '/';
public:
    Darray();
    explicit Darray(const ptrdiff_t length);
    Darray(const std::initializer_list<double> array);
    Darray(const Darray& obj);

    Darray& operator=(const Darray& rhs);

    ptrdiff_t Size() const;
    
    void Resize(const ptrdiff_t size);
    void Insert(const ptrdiff_t ind, const double value);
    void Remove(const ptrdiff_t ind);

    double& operator[](const ptrdiff_t ind);
    const double& operator[](const ptrdiff_t ind) const;


    ~Darray();

};



#endif // !Darray_HPP