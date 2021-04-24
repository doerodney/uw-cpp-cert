#ifndef INC_CHARQUEUE1_H
#define INC_CHARQUEUE1_H

#include <cstddef>
#include <memory>

class CharQueue1 {
public:
    CharQueue1();
    CharQueue1(std::size_t size);
    CharQueue1(const CharQueue1& src); // copy constructor

    void enqueue(char ch);
    char dequeue();

    bool isEmpty() const;
    void swap(CharQueue1& src);

    std::size_t capacity() const;

    CharQueue1& operator=(CharQueue1 src);

private:
    void grow();
    std::unique_ptr<char[]> myBuf;
    std::size_t myCap;
    std::size_t myLen;

};

#endif
