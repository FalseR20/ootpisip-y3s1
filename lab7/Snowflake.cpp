#include "Snowflake.h"


Snowflake::Snowflake(QWidget *parent): QWidget(parent) {
    resize(start * 2, start * 2);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);
}

void Snowflake::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QPen(QColor(0xADD8E6), 15, Qt::SolidLine, Qt::RoundCap));

    auto rad = ::qDegreesToRadians(spiralLen);
    painter.translate(start + spiralLen * cos(rad), start + spiralLen * sin(rad));
    spiralLen++;

    double len(50);
    for (int i = 0; i < 3; i++) {
        auto radians = ::qDegreesToRadians(-2.0 * spiralLen + 120.0 * i);
        x = len * cos(radians);
        y = len * sin(radians);
        QLineF line(-x, -y, x, y);
        painter.drawLine(line);
    }
}
