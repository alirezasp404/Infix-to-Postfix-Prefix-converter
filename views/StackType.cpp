

#include "StackType.h"

StackType::StackType(int capacity) {
    elements = new QString[capacity];
    size = capacity;
    top = -1;
}

StackType::~StackType() {
    delete[] elements;
}

void StackType::push(QString element) {
    if (isFull())
        exit(EXIT_FAILURE);
    elements[++top] = element;
}

QString StackType::pop() {
    if (isEmpty())
        exit(EXIT_FAILURE);
    return elements[top--];
}

QString StackType::peek() {
    if (!isEmpty())
        return elements[top];
    else {
        exit(EXIT_FAILURE);
    }
}

bool StackType::isEmpty() {
    return (top == -1);
}

bool StackType::isFull() {
    return (top == size - 1);
}

