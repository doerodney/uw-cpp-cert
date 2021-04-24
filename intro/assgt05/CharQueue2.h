#ifndef INC_CharQueue22_H
#define INC_CharQueue22_H

#include <cstddef>
#include <deque>

class CharQueue2
{
public:
    CharQueue2();
    CharQueue2(std::size_t size);  // DNA for std::deque implementation
    CharQueue2(const CharQueue2& src) = default;

    void enqueue(char ch);
    char dequeue();

    bool isEmpty() const;
    void swap(CharQueue2& src);

    std::size_t capacity() const;

    // CharQueue2& operator=(CharQueue2 src);
    CharQueue2& operator=(const CharQueue2 &src) = default;  // Necessary to change arg to use default

private:
    std::deque<char> myDeque;
};

#endif