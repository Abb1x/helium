# data/

Data structures implementations

## dll.c - Doubly Linked List

Contains the following functions (`object` is a `DLL` object using OOP):
- `DoublyLinkedList()` creates a new object, returns type `DLL`
- `object.printstr(DLL* self)` Prints the list assuming the members are strings
- `object.append(void* data, DLL* self)`Appends a node to the list

## vector.c - Dynamic array

Contains the following functions (`object` is a `Vector` object using OOP):
- `Vector_new()`Creates a new vector object, returns type `Vector`
- `object.push_back(void* data, Vector* self)`Appends an element at the end of the vector
- `object.pop_back(Vector* self)`Removes the last element of the vector
- `object.remove(int index, Vector* self)`Removes the element that is at the index specified.
