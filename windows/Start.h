

#ifndef INFIXCONVERTER_START_H
#define INFIXCONVERTER_START_H

#include <QGraphicsView>
#include "../views/Background.h"
#include "../views/TextField.h"
#include "../views/Button.h"
#include "../views/Label.h"

class Start : public QGraphicsView {

private:
    QGraphicsScene *scene;
    Background* background;
    Label* titleLabel;
    Label* resultLabel;
    TextField* infixTextField;
    Button* prefixConvertButton;
    Button* postfixConvertButton;
    Button* exitButton;
    QString infixExpression;
public:
    void addItems();
    Start();
    ~Start();
    int checkPriority(QChar);
public slots:
    void prefixConvert();
    void postfixConvert();
    void exitFunc();
};

#endif //INFIXCONVERTER_START_H
