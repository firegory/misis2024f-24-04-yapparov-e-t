#include <iosfwd>
#include<sstream>
#include <stdarg.h>
#include<initializer_list>

#ifndef arrayd_HPP
#define arrayd_HPP

class ArrayD
{
private:
    ptrdiff_t len = 0;
    ptrdiff_t allocatedMemory = 0;
    double* startAdress;

    static const char sep = '/';
public:
    ArrayD();
    explicit ArrayD(const ptrdiff_t length);
    ArrayD(const std::initializer_list<double> array);
    ArrayD(const ArrayD& obj);
    ArrayD(ArrayD&& obj);
    

    ArrayD& operator=(const ArrayD& rhs);
    ArrayD& operator=(ArrayD&& rhs);

    ptrdiff_t Size() const;
    
    void Resize(const ptrdiff_t size);
    void Insert(const ptrdiff_t ind, const double value);
    void Remove(const ptrdiff_t ind);

    double& operator[](const ptrdiff_t ind);
    const double& operator[](const ptrdiff_t ind) const;


    ~ArrayD();

};



#endif // !ArrayD_HPP