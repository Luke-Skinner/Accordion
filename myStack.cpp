#include "myStack.h"

template <class type>
myStack<type>::myStack() {
    size = 0;
    capacity = 5;
    stackElements = new type[capacity];
}

template <class type>
myStack<type>::myStack(const myStack<type>& copy) {
    stackElements = nullptr;
    copyStack(copy);
}

template <class type>
const myStack<type>& myStack<type>::operator=(const myStack<type>& rhs) {
    if (this != &rhs) {
        clearStack();
        copyStack(rhs);
    }
    return *this;
}

template <class type>
myStack<type>::~myStack() {
    clearStack();
}

template <class type>
void myStack<type>::push(const type& item) {
    if (size == capacity) {
        capacity *= 2;
        type* newArray = new type[capacity];
        for (std::size_t i = 0; i < size; ++i) {
            newArray[i] = stackElements[i];
        }
        delete[] stackElements;
        stackElements = newArray;
    }
    stackElements[size] = item;
    size++;
}

template <class type>
type myStack<type>::peek() const {
    if (size == 0) {
        throw std::out_of_range("Stack is empty");
    }
    return stackElements[size - 1];
}

template <class type>
std::size_t myStack<type>::getSize() const {
    return size;
}

template <class type>
type myStack<type>::pop() {
    if (size == 0) {
        throw std::out_of_range("Stack is empty");
    }
    size--;
    return stackElements[size];
}

template <class type>
bool myStack<type>::isEmpty() const {
    return size == 0;
}

template <class type>
void myStack<type>::clearStack() {
    delete[] stackElements;
    stackElements = nullptr;
    size = 0;
    capacity = 0;
}

template <class type>
void myStack<type>::copyStack(const myStack<type>& copyThisStack) {
    size = copyThisStack.size;
    capacity = copyThisStack.capacity;
    if (stackElements) delete[] stackElements;
    stackElements = new type[capacity];
    for (std::size_t i = 0; i < size; ++i) {
        stackElements[i] = copyThisStack.stackElements[i];
    }
}

