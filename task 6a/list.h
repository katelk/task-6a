#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <cstddef>

enum ERR_CODE { STACK_UNDERFLOW };

class list
{
public:
    virtual void push(int e) = 0;
    virtual int pop() = 0;
    virtual const int& getFront() const = 0;
    virtual int isEmpty() const = 0;
    virtual size_t size() const = 0;
    virtual list& operator = (const list& a) = 0;
    virtual void free() = 0;
    friend std::ostream& operator <<(std::ostream& stream, list& a)
    {
        a.print(stream);
        return stream;
    }
    friend std::istream& operator >> (std::istream& in, list& a)
    {
        int e;
        in >> e;
        a.push(e);
        return in;
    }

protected:
    struct node
    {
        int data;
        struct node* next;
    };
    virtual void print(std::ostream& stream) const = 0;
};

#endif // LIST_H_INCLUDED

