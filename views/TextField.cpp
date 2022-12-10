
#include "TextField.h"
#include <QFont>
#include <QPainter>
#include <QTextDocument>
#include<QGraphicsTextItem>
#include <QStyleOptionGraphicsItem>
#include <QStyle>
TextField::TextField(int width, int height,QString color) : width(width), height(height), QGraphicsTextItem() {
    setDefaultTextColor(QColor(color));
    QFont font;
    font.setPixelSize(23);
    font.setBold(true);
    setFont(font);
    setTextInteractionFlags(Qt::TextEditorInteraction);
    setTextWidth(width);
    document()->setDocumentMargin(10);
}

void TextField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pixmap(":images/textBG");
    pixmap=pixmap.scaled(width,height);
    painter->setBrush(pixmap);
    painter->drawRect(boundingRect());
    QStyleOptionGraphicsItem newOption(*option);
    newOption.state=QStyle::State_None;
    QGraphicsTextItem::paint(painter, &newOption, widget);
}

QRectF TextField::boundingRect() const {
    auto rect=QGraphicsTextItem::boundingRect();
    rect.setWidth(width);
    rect.setHeight(height);
    return rect;
}