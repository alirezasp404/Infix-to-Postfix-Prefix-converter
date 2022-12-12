

#include "StackType.h"

StackType::StackType(int capacity) {
    elements=new QChar [capacity];
    size=capacity;
    top = -1;
}
StackType::~StackType() {
delete [] elements;
}
void StackType::push(QChar element) {
    if (isFull())
        exit(EXIT_FAILURE);
    elements[++top] = element;
}

QChar StackType::pop() {
    if (isEmpty())
        exit(EXIT_FAILURE);
    return elements[top--];
}

QChar StackType::peek() {
    if (!isEmpty())
        return elements[top];
    else {
        exit(EXIT_FAILURE);
    }
}
 bool StackType::isEmpty(){
        return (top == -1);
    }
bool StackType::isFull() {
    return (top == size - 1);
}

