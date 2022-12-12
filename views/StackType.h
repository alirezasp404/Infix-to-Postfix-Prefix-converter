
#ifndef INFIXCONVERTER_STACKTYPE_H
#define INFIXCONVERTER_STACKTYPE_H


#include <QString>

class StackType {
public:
    int size;
    StackType(int capacity);
    ~StackType();

    void push(QChar);
    QChar pop();
    QChar peek();
    bool isEmpty();
    bool isFull();
private:
    QChar* elements;
    int top;
};


#endif //INFIXCONVERTER_STACKTYPE_H
