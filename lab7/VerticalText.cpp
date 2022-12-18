#include "VerticalText.h"


VerticalText::VerticalText(QWidget *parent): QWidget{parent} {
    resize(300, 400);
}

void VerticalText::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    painter.setFont(QFont("Gothic", 32));
    painter.rotate(90);

    painter.translate(50, -250);
    painter.drawText(rect(), "Важно");

    painter.translate(0, 50);
    painter.drawText(rect(), "Какой-то готический текст");
    //    painter.

}
