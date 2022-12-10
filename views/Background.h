//
// Created by Alireza on 12/9/2022.
//

#ifndef INFIXCONVERTER_BACKGROUND_H
#define INFIXCONVERTER_BACKGROUND_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Background : public QGraphicsPixmapItem{

public:
    bool initialized{false};
    Background(QGraphicsItem *parent=nullptr);
    void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};



#endif //INFIXCONVERTER_BACKGROUND_H
