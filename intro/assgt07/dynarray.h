#ifndef INC_DYNARRAY_H
#define INC_DYNARRAY_H

#include <cstddef>
#include <ostream>
#include <vector>


class DynamicArray {
public:
    DynamicArray();

    // Overwrites an existing element, or adds a new element as necessary.
    // If an element exists at index, the existing element is overwritten.
    // If an element does not exist at the index, a new element is added. If necessary, the array
    // must expand to accommodate the new element. 
    void put(int index, int value);

    // returns the element at index.
    int get(int index) const;

    // removes the element at the specified index. The array may contract.
    void remove(int index);

    // get the value used for unassigned positions.
    int get_undef_value() const;

    // const and non-const access:
    int operator[](int index) { return this->get(index); }
    const int operator[](int index) const { return this->get(index); }

    // ostream operator overide:
    friend std::ostream& operator<< (std::ostream& stream, DynamicArray& probe);

private:
    std::vector<int> storage;
    
};




#endif