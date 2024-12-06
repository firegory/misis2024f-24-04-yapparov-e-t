#include <iosfwd>
#include<sstream>
#include <stdarg.h>
#include<initializer_list>

#ifndef StackL_HPP
#define StackL_HPP

struct Node
{
    uint8_t value = 0;
    Node* next = nullptr;

    explicit Node(const uint8_t val);
    Node(const uint8_t val, Node* nextElem);
};
class StackL
{
private:
    Node* head = nullptr;
public:
    StackL() = default;
    StackL(const StackL& obj);
    StackL(StackL&& obj) noexcept;
    
    [[nodiscard]] StackL& operator=(const StackL& rhs);
    [[nodiscard]] StackL& operator=(StackL&& rhs) noexcept;
    
    void Push(const uint8_t value);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    void Clear() noexcept;
    uint8_t& Top();

    ~StackL();
};



#endif // !StackL_HPP