

#include "Start.h"
#include "../views/StackType.h"

Start::Start() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    setScene(scene);
    background = new Background();
    scene->addItem(background);
    addItems();
}

Start::~Start() {
    delete infixTextField;
    delete background;
    delete postfixConvertButton;
    delete prefixConvertButton;
    delete titleLabel;
    delete resultLabel;
    delete exitButton;
    delete scene;
}

void Start::addItems() {
    titleLabel = new Label(40, "#6D2CB5");
    titleLabel->setPlainText("Infix to Postfix/Prefix converter");
    scene->addItem(titleLabel);
    titleLabel->setPos(50, 50);

    infixTextField = new TextField(width() / 3.1, 55, "#6D2CB5");
    infixTextField->setPlainText("Please enter infix expression");
    scene->addItem(infixTextField);
    infixTextField->setPos(width() / 6, height() / 3);

    prefixConvertButton = new Button(240, 150, "#ac00b7");
    prefixConvertButton->setPlainText("Prefix Convert");
    scene->addItem(prefixConvertButton);
    prefixConvertButton->setPos(width() / 6, height() / 2.1);
    connect(prefixConvertButton, &Button::press, this, &Start::prefixConvert);

    postfixConvertButton = new Button(240, 150, "#2260b3");
    postfixConvertButton->setPlainText("Postfix Convert");
    scene->addItem(postfixConvertButton);
    postfixConvertButton->setPos(width() / 3, height() / 2.1);
    connect(postfixConvertButton, &Button::press, this, &Start::postfixConvert);

    resultLabel = new Label(30, "");
    resultLabel->setPlainText("");
    scene->addItem(resultLabel);
    resultLabel->setPos(width() / 6, height() / 1.6);

    exitButton = new Button(80, 150, "#6D2CB5");
    exitButton->setPlainText("Exit");
    scene->addItem(exitButton);
    exitButton->setPos(width() / 2, height() - 65);
    connect(exitButton, &Button::press, this, &Start::exitFunc);
}


void Start::exitFunc() {
    exit(0);
}

void Start::prefixConvert() {
    infixExpression = infixTextField->toPlainText();


    resultLabel->setDefaultTextColor("#ac00b7");
    resultLabel->setPlainText("Result : " );
}

void Start::postfixConvert() {
    infixExpression = infixTextField->toPlainText();
    QString postfixExpression="";
    StackType operandsStack(infixExpression.length());
    for (int i = 0; i < infixExpression.length(); ++i) {
        if(infixExpression[i]>='0' && infixExpression[i]<='9')//If it's a number
            postfixExpression+=infixExpression[i];
        else if(infixExpression[i]=='(')//If  it's opening bracket
            operandsStack.push(infixExpression[i]);
        else if(infixExpression[i]==')') {//If  it's closing bracket
            while(operandsStack.peek()!='(')
                postfixExpression += operandsStack.pop();
            operandsStack.pop();
        }
        else{
            if(checkPriority(infixExpression[i])!=-1) {
                //If it's an operand
                while (!operandsStack.isEmpty() &&
                       checkPriority(infixExpression[i]) <= checkPriority(operandsStack.peek()))
                    postfixExpression += operandsStack.pop();
                operandsStack.push(infixExpression[i]);
            }else{
                resultLabel->setPlainText("Please enter correct Expression !");
                resultLabel->setDefaultTextColor("red");
                return;
            }
        }
    }
    while(!operandsStack.isEmpty())
        postfixExpression += operandsStack.pop();
    resultLabel->setDefaultTextColor("#2260b3");
    resultLabel->setPlainText("Result : " + postfixExpression);
}

int Start::checkPriority(QChar operand) {
        if(operand == '+' || operand =='-')
            return 1;

        else if(operand == '*' || operand =='/')
            return 2;

        else if(operand == '^')
            return 3;
        else
            return -1;
    }



