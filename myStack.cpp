/*
    Name: Luke Skinner, 2002053024, 1001, ASSIGNMENT_1
    Description: Implementation file for stack class
    Input: Items to be added in to stack
    Output: Varies by function stack class variables
*/
#include "myStack.h"

//Constructor for the stack
template <class type>
myStack<type>::myStack() {
    size = 0;
    capacity = 5;
    stackElements = new type[capacity];
}

//Copy constructor for the stack
template <class type>
myStack<type>::myStack(const myStack<type>& copy) {
    stackElements = nullptr;
    copyStack(copy);
}

//Overloads the = operator for the stack
template <class type>
const myStack<type>& myStack<type>::operator=(const myStack<type>& rhs) {
    //Checks if the stack is not the same as the rhs
    if (this != &rhs) {
        clearStack();
        copyStack(rhs);
    }
    return *this;
}

//Destructor for the stack
template <class type>
myStack<type>::~myStack() {
    clearStack();
}

//Pushes a new item onto the stack
template <class type>
void myStack<type>::push(const type& item) {
    //Checks if the stack is full
    if (size == capacity) {
        //Doubles the capacity
        capacity *= 2;
        type* newArray = new type[capacity];
        //Copies the stack to the new array
        for (std::size_t i = 0; i < size; ++i) {
            newArray[i] = stackElements[i];
        }
        //Deletes the old array
        delete[] stackElements;
        stackElements = newArray;
    }
    stackElements[size] = item;
    size++;
}

//Peeks at the top of the stack
template <class type>
type myStack<type>::peek() const {
    //Checks if the stack is empty
    if (size == 0) {
        throw std::out_of_range("Stack is empty");
    }
    return stackElements[size - 1];
}

//Gets the size of the stack
template <class type>
std::size_t myStack<type>::getSize() const {
    return size;
}

//Pops the top of the stack
template <class type>
type myStack<type>::pop() {
    //Checks if the stack is empty
    if (size == 0) {
        throw std::out_of_range("Stack is empty");
    }
    size--;
    return stackElements[size];
}

//Checks if the stack is empty
template <class type>
bool myStack<type>::isEmpty() const {
    return size == 0;
}

//Clears the stack
template <class type>
void myStack<type>::clearStack() {
    delete[] stackElements;
    stackElements = nullptr;
    size = 0;
    capacity = 0;
}

//Copies the stack
template <class type>
void myStack<type>::copyStack(const myStack<type>& copyThisStack) {
    size = copyThisStack.size;
    capacity = copyThisStack.capacity;
    //Deletes the old array if it exists
    if (stackElements) delete[] stackElements;
    stackElements = new type[capacity];
    //Copies the stack to the new array
    for (std::size_t i = 0; i < size; ++i) {
        stackElements[i] = copyThisStack.stackElements[i];
    }
}

