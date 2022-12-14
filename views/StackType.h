
#ifndef INFIXCONVERTER_STACKTYPE_H
#define INFIXCONVERTER_STACKTYPE_H


#include <QString>

class StackType {
public:
    int size;
    StackType(int);
    ~StackType();

    void push(QString);
    QString pop();
    QString peek();
    bool isEmpty();
    bool isFull();
private:
    QString* elements;
    int top;
};


#endif //INFIXCONVERTER_STACKTYPE_H
