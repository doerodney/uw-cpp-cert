// Copyright 2021 placate cpplint
#include <climits>
#include "dynarray.h"

const int undef = -INT_MAX;  // A poor man's integer marker for undefined.

/*--
NOTE:  This author is Perl-poisoned.  In Perl, if you assign a value at index 
       26 in an empty list, Perl will happily fill positions 0..25 with undef.

NOTE:  I was tempted to implement this with a map<int, int>, but that felt 
       like cheating.  This is how Lua implements arrays.  In Lua, an array
       is implemented as a hash with index values as keys.
--*/ 

DynamicArray::DynamicArray() : storage() {
}

int DynamicArray::get(int index) const {
    int result = undef;

    // Return undef value for invalid index:
    if ((index >= 0) && ((std::size_t) index < storage.size())) {
        result = storage.at(index);
    }

    return result;
}


void DynamicArray::put(int index, int value) {
    // Do nothing for negative index:
    if (index >= 0) {
        // Grow the storage as necessary,
        // storing the undef value in unassigned slots:
        while (storage.size() <= (std::size_t) index) {
            storage.push_back(undef);
        }

        storage[index] = value;
    }
}


void DynamicArray::remove(int index) {
    // Only respond to a valid index:
    if ((index >= 0) && ((std::size_t) index < storage.size())) {
        // Advance the iterator to the index:
        auto pos = storage.begin();
        for (auto i = 0; i < index; i++) {
            ++pos;
        }
        storage.erase(pos);
        storage.shrink_to_fit();
    }
}


int DynamicArray::get_undef_value() const {
    return undef;
}


std::ostream& operator<<(std::ostream& stream, DynamicArray& da) {
    // Stream an opening brace:
    stream  << "storage = { ";
    
    // Stream the values in the storage:
    for (int n :da.storage) {
        stream << n << ", ";
    }
    
    // Stream the closing brace:
    stream << "}; \n";
    
    return stream;
}

/*--
Q:  Why are the compiler-generated copy constructor and copy assignment 
operators sufficient for DynamicArray?

A:  Because the implementation is based upon an STL container class, 
which implements those operations.  Use the STL and have a nice life.
--*/