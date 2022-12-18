#ifndef FLYINGFIGURES_H
#define FLYINGFIGURES_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QtMath>


class Snowflake: public QWidget {
Q_OBJECT
public:
    explicit Snowflake(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

private:
    QTimer *timer;
    double x = 240;
    double y = 500;
    double spiralLen = 0;
    double start = 500;
};


#endif // FLYINGFIGURES_H
