

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
    infixTextField->setPlainText("Enter infix expression");
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
    if (infixTextField->toPlainText() == "") {
        warning();
        return;
    }
    int numOfOperands = 0;
    int numOfOperators = 0;
    infixExpression = infixTextField->toPlainText();
    StackType operators(infixExpression.length());
    StackType operands(infixExpression.length());

    for (int i = 0; i < infixExpression.length(); i++) {
        if (infixExpression[i] >= '0' && infixExpression[i] <= '9') {
            operands.push(infixExpression[i]);
            numOfOperands++;
        } else if (infixExpression[i] == '(') {
            if (infixExpression[i + 1] == '-') {
                operands.push('-' + infixExpression[i + 2]);
                numOfOperands++;
                i += 3;
            } else
                operators.push(infixExpression[i]);

        } else if (infixExpression[i] == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                QString operand1 = operands.pop();
                QString operand2 = operands.pop();
                QString op = operators.pop();
                QString temp = op + operand2 + operand1;
                operands.push(temp);
            }
            if (operators.isEmpty()) {
                warning();
                return;
            }
            operators.pop();
        } else if (checkPriority(infixExpression[i]) != -1) {
            numOfOperators++;
            while (!operators.isEmpty() &&
                   checkPriority(infixExpression[i]) <= checkPriority(operators.peek())) {
                QString operand1 = operands.pop();
                QString operand2 = operands.pop();
                QString op = operators.pop();
                QString temp = op + operand2 + operand1;
                operands.push(temp);
            }
            operators.push(infixExpression[i]);
        } else {
            warning();
            return;
        }
    }
    while (!operators.isEmpty()) {
        if (operators.peek() == '(' || operators.peek() == ')') {
            warning();
            return;
        }
        QString operand1 = operands.pop();
        QString operand2 = operands.pop();
        QString op = operators.pop();
        QString temp = op + operand2 + operand1;
        operands.push(temp);
    }
    if (numOfOperands != (numOfOperators + 1))
        warning();
    else {
        resultLabel->setDefaultTextColor("#ac00b7");
        resultLabel->setPlainText("Result : " + operands.peek());
    }
}

void Start::postfixConvert() {
    if (infixTextField->toPlainText() == "") {
        warning();
        return;
    }
    int numOfOperands = 0;
    int numOfOperators = 0;
    infixExpression = infixTextField->toPlainText();
    QString postfixExpression = "";
    StackType operators(infixExpression.length());
    for (int i = 0; i < infixExpression.length(); ++i) {
        if (infixExpression[i] >= '0' && infixExpression[i] <= '9') {//If it's a number
            postfixExpression += infixExpression[i];
            numOfOperands++;
        } else if (infixExpression[i] == '(') {//If  it's opening bracket
            if (infixExpression[i + 1] == '-') {
                postfixExpression += '-' + infixExpression[i + 2];
                i += 3;
                numOfOperands++;
            } else
                operators.push(infixExpression[i]);
        } else if (infixExpression[i] == ')') {//If  it's closing bracket
            while (!operators.isEmpty() && operators.peek() != '(')
                postfixExpression += operators.pop();
            if (operators.isEmpty()) {
                warning();
                return;
            }
            operators.pop();
        } else if (checkPriority(infixExpression[i]) != -1) {//If it's an operator
            numOfOperators++;
            while (!operators.isEmpty() &&
                   checkPriority(infixExpression[i]) <= checkPriority(operators.peek()))
                postfixExpression += operators.pop();
            operators.push(infixExpression[i]);
        } else {
            warning();
            return;
        }
    }
    while (!operators.isEmpty()) {
        if (operators.peek() == '(' || operators.peek() == ')') {
            warning();
            return;
        }
        postfixExpression += operators.pop();
    }
    if (numOfOperands != (numOfOperators + 1))
        warning();
    else {
        resultLabel->setDefaultTextColor("#2260b3");
        resultLabel->setPlainText("Result : " + postfixExpression);
    }
}

int Start::checkPriority(QString operand) {
    if (operand == '+' || operand == '-')
        return 1;

    else if (operand == '*' || operand == '/')
        return 2;

    else if (operand == '^')
        return 3;
    else
        return -1;
}

void Start::warning() {
    resultLabel->setPlainText("Please enter correct Expression !");
    if (resultLabel->defaultTextColor() != "red")
        resultLabel->setDefaultTextColor("red");
    else
        resultLabel->setDefaultTextColor("yellow");

}


