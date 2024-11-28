#include <iosfwd>
#include<sstream>
#include <stdarg.h>
#include<initializer_list>

#ifndef arrayt_HPP
#define arrayt_HPP


template<typename T>
class ArrayT
{
private:
    ptrdiff_t len = 0;
    ptrdiff_t allocatedMemory = 0;
    T* startAdress;
public:
    ArrayT()
    {
        len = 0;
        allocatedMemory = 0;
        startAdress = new T[0];
    }
    explicit ArrayT(const ptrdiff_t length)
    {
        if (length <= 0)
        {
            throw std::out_of_range("Can not make an arry with tis length");
        }
        len = length;
        allocatedMemory = length;
        startAdress = new T[allocatedMemory];
        std::memset(startAdress, 0, sizeof(T) * len);
    }
    ArrayT(const std::initializer_list<T> array)
    {
        len = array.size();
        allocatedMemory = len;
        startAdress = new T[allocatedMemory];
        for (int i = 0; i < len; i++)
        {
            startAdress[i] = array.begin()[i];
        }
    }
    ArrayT(const ArrayT<T>& obj)
    {
        len = obj.len;
        allocatedMemory = obj.allocatedMemory;
        startAdress = new T[allocatedMemory];
        std::copy(obj.startAdress, obj.startAdress + len, startAdress);
    }
    ArrayT(ArrayT<T>&& obj) noexcept
    {
        std::swap(len, obj.len);
        std::swap(allocatedMemory, obj.allocatedMemory);
        startAdress = obj.startAdress;
        obj.startAdress = nullptr;
    }
    
    [[nodiscard]] ArrayT& operator=(const ArrayT<T>& rhs) 
    {
        if (this != &rhs)
        {
            len = rhs.len;
            allocatedMemory = len;
            startAdress = new T[allocatedMemory];
            std::copy(rhs.startAdress, rhs.startAdress + len, startAdress);
        }
        return *this;
    }
    [[nodiscard]] ArrayT& operator=(ArrayT<T>&& rhs) noexcept 
    {
        if (this != &rhs)
        {
            std::swap(len, rhs.len);
            std::swap(allocatedMemory, rhs.allocatedMemory);
            startAdress = rhs.startAdress;
            rhs.startAdress = nullptr;
        }
        return *this;
    }

    [[nodiscard]] ptrdiff_t Size() const noexcept 
    {
        return len;
    }
    
    void Resize(const ptrdiff_t size)
    {
        if (size < 0)
        {
            throw std::out_of_range("Can not make an arry with tis length");
        }
        if (size == len)
        {
            return;
        }
        if (size < len)
        {
            T* temp = new T[size];
            std::copy(startAdress, startAdress + size, temp);
            startAdress = temp;
            allocatedMemory = size;
            len = size;
        }
        else
        {
            if (allocatedMemory < size)
            {
                if (allocatedMemory * 2 < size)
                {
                    allocatedMemory = size;
                }
                else
                {
                    allocatedMemory *= 2;
                }
                T* temp = new T[allocatedMemory];
                std::copy(startAdress, startAdress + len, temp);
                std::memset(&temp[len], 0, sizeof(T) * (allocatedMemory - len));
                startAdress = temp;
            }
            len = size;
        }
    }
    void Insert(const ptrdiff_t ind, const T value)
    {
        if (ind > len || ind < 0)
        {
            throw std::out_of_range("index out of range");
        }
        this->Resize(len + 1);
        std::copy(&startAdress[ind], startAdress + len, &startAdress[ind + 1]);
        startAdress[ind] = value;

    }
    void Remove(const ptrdiff_t ind)
    {
        if (ind >= len || ind < 0)
        {
            throw std::out_of_range("index out of range");
        }
        std::copy(&startAdress[ind + 1], startAdress + len, &startAdress[ind]);
        this->Resize(len - 1);
    }

    [[nodiscard]] T& operator[](const ptrdiff_t ind) 
    {
        if (ind >= len || ind < 0)
        {
            throw std::out_of_range("index out of range");
        }
        return startAdress[ind];
    }
    [[nodiscard]] const T& operator[](const ptrdiff_t ind) const 
    {
        if (ind >= len || ind < 0)
        {
            throw std::out_of_range("index out of range");
        }
        return startAdress[ind];
    }

    ~ArrayT()
    {
        delete(startAdress);
    }

};



#endif // !ArrayT_HPP