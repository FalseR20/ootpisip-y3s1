#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include<QMouseEvent>


class Widget: public QWidget {
Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    ~Widget();

    QTableWidget *my_table;
    QGridLayout *first_grid;
    QVBoxLayout *my_box;
    QVBoxLayout *my_box2;
    QPushButton *setValuesButton;
    QPushButton *bubbleSortButton;
    QVector<QVector<int>> *my_array;

    QLabel *label;
    QPushButton *add;
    QPushButton *del;

private slots:

    void setTableValues();

    void bubbleSort();
    //   void add_slot();
    //   void del_slot();

private:
};


#endif // WIDGET_H
