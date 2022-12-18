#ifndef LIGHTWORDS_H
#define LIGHTWORDS_H

#include <QObject>
#include <QWidget>
#include <QPainter>


class VerticalText: public QWidget {
Q_OBJECT
public:
    explicit VerticalText(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);
};


#endif // LIGHTWORDS_H
