//
// Created by Alireza on 12/9/2022.
//

#ifndef INFIXCONVERTER_TEXTFIELD_H
#define INFIXCONVERTER_TEXTFIELD_H

#include <QGraphicsTextItem>

class TextField : public QGraphicsTextItem {
private:
    int width{};
    int height{};
public:
    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TextField(int width, int height,QString color);
};


#endif //INFIXCONVERTER_TEXTFIELD_H
