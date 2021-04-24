// Copyright 2021 cpplint user
#include <utility>  // std::move
#include "CharQueue1.h"


static const std::size_t defaultCapacity = 32;


CharQueue1::CharQueue1() : 
    myBuf(std::make_unique<char[]>(defaultCapacity)),
    myCap(defaultCapacity), 
    myLen(0) {
    // nothing to do    
}


CharQueue1::CharQueue1(size_t size) :
    myBuf(std::make_unique<char[]>(size)),
    myCap(size),
    myLen(0)  {
    // nothing to do
 }


CharQueue1::CharQueue1(const CharQueue1& src) :
    myBuf(std::make_unique<char[]>(src.myCap)),
    myCap(src.myCap),
    myLen(src.myLen)
{                
    // Copy the contents of the src buffer to this myBuf:
    for (size_t i = 0; i < src.myLen; i++) {
        myBuf[i] = src.myBuf[i];
    }
}


void CharQueue1::grow() {
    // Allocate the new storage:
    std::size_t newCap = myLen + defaultCapacity;
    auto buf = std::make_unique<char[]>(newCap);

    // Copy the contents of the current storage to the new storage:
    for (size_t i = 0; i < myLen; i++) {
        buf[i] = myBuf[i];
    }
    // std::memcpy(buf, myBuf, myLen);

    // Move buf into myBuf:
    myBuf = std::move(buf);
    myCap = newCap;
}


// Inserts a value at the start of the queue.
void CharQueue1::enqueue(char ch) {
    
    // Shift the queue contents one position to the right:
    for (int i = myLen - 1; i >= 0; i--) {
        myBuf[i + 1] = myBuf[i];
    }

    // Add the new value to the queue:
    myBuf[0] = ch;
    myLen++;
    
    // Is it necessary to resize?
    if (myLen == myCap) {
        grow();
    }
}


// Removes a value from the end of the queue.
char CharQueue1::dequeue() {
    char result = 'Z';  // Need to throw here if empty...
    if (!isEmpty()) {
        result = myBuf[myLen - 1];
        myLen--;
    }
    return result;
}


bool CharQueue1::isEmpty() const {
    return myLen == 0; 
}


void CharQueue1::swap(CharQueue1& src){
    std::swap(myBuf, src.myBuf);
    std::swap(myLen, src.myLen);
    std::swap(myCap, src.myCap);
}


std::size_t CharQueue1::capacity() const {
    return myCap;
}


CharQueue1& CharQueue1::operator=(CharQueue1 src) {
    this->swap(src);
    return *this;
}
