

#include "Start.h"

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
Start::~Start(){
    delete infixExpression;
    delete background;
    delete postfixConvert;
    delete prefixConvert;
    delete titleLabel;
    delete resultLabel;
    delete exitButton;
    delete scene;
}

void Start::addItems() {
    titleLabel = new Label(40, "white");
    titleLabel->setPlainText("Infix to Postfix/Prefix converter");
    scene->addItem(titleLabel);
    titleLabel->setPos(50, 50);

    infixExpression = new TextField(width()/3.1, 55,"white");
    infixExpression->setPlainText("Please enter infix expression");
    scene->addItem(infixExpression);
    infixExpression->setPos(width() /6, height()/3);

    prefixConvert = new Button(240, 150,"#ac00b7");
    prefixConvert->setPlainText("Prefix Convert");
    scene->addItem(prefixConvert);
    prefixConvert->setPos(width() /6, height() / 2.1);
    connect(prefixConvert, &Button::press, this, &Start::preConvert);

    postfixConvert = new Button(240, 150,"#2260b3");
    postfixConvert->setPlainText("Postfix Convert");
    scene->addItem(postfixConvert);
    postfixConvert->setPos(width() /3 , height() / 2.1);
    connect(postfixConvert, &Button::press, this, &Start::postConvert);

    resultLabel = new Label(30,"white");
    resultLabel->setPlainText("");
    scene->addItem(resultLabel);
    resultLabel->setPos(width() /6, height()/1.6);

    exitButton = new Button(80, 150,"white");
    exitButton->setPlainText("Exit");
    scene->addItem(exitButton);
    exitButton->setPos(width() /2 , height()-65);
    connect(exitButton, &Button::press, this, &Start::exitFunc);
}

void Start::preConvert() {
    resultLabel->setDefaultTextColor("#ac00b7");
    resultLabel->setPlainText("Result :");
}

void Start::postConvert() {
    resultLabel->setDefaultTextColor("#2260b3");
    resultLabel->setPlainText("Result :");
}

void Start::exitFunc() {
exit(0);
}
