

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
    TextField* infixExpression;
    Button* prefixConvert;
    Button* postfixConvert;
    Button* exitButton;
public:
    void addItems();
    Start();
    ~Start();
public slots:
    void preConvert();
    void postConvert();
    void exitFunc();
};


#endif //INFIXCONVERTER_START_H
