#include <iosfwd>
#include<sstream>
#include <stdarg.h>
#include<initializer_list>

#ifndef queuea_HPP
#define queuea_HPP

class QueueA
{
private:
    ptrdiff_t allocatedMemory = 0;
    ptrdiff_t head = 0;
    ptrdiff_t tail = 0;
    uint8_t* startAdress = nullptr;
    bool empty = true;
public:
    QueueA() = default;
    QueueA(const QueueA & obj);
    QueueA(QueueA && obj) noexcept;

    [[nodiscard]] QueueA& operator=(const QueueA & rhs);
    [[nodiscard]] QueueA& operator=(QueueA && rhs) noexcept;

    void Push(const uint8_t value);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    void Clear() noexcept;
    uint8_t& Top();

    ~QueueA();

    void print();
};



#endif // !QueueA_HPP