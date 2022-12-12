#include "widget.h"
#include<QRandomGenerator>
#include <QLabel>
#include<iostream>


Widget::Widget(QWidget *parent): QWidget(parent) {
    this->resize(620, 400);
    first_grid = new QGridLayout(this);
    my_table = new QTableWidget(10, 3);
    my_box = new QVBoxLayout();
    my_box2 = new QVBoxLayout();
    my_box->addWidget(my_table);

    first_grid->addLayout(my_box, 0, 0);
    first_grid->addLayout(my_box2, 0, 1);

    label = new QLabel();

    setValuesButton = new QPushButton();
    setValuesButton->setText("set value");
    bubbleSortButton = new QPushButton;
    setValuesButton->setToolTip("Заполнить таблицу");
    bubbleSortButton->setText("Bubble sort");
    bubbleSortButton->setToolTip("Сортировка пузырьком");
    bubbleSortButton->setEnabled(false);
    add = new QPushButton;

    add->setText("Сортировать по убыванию");
    del = new QPushButton;
    del->setText("Сортировать по возрастанию");

    my_box->addWidget(setValuesButton);
    my_box2->addWidget(bubbleSortButton);

    my_box2->addWidget(label);

    my_array = new QVector<QVector<int>>();

    connect(setValuesButton, SIGNAL(clicked(bool)), this, SLOT(setTableValues()));
    connect(bubbleSortButton, SIGNAL(clicked(bool)), this, SLOT(bubbleSort()));
}

//void Widget::del_slot(){
//    if (indexArray->contains(my_table->currentColumn())){
//        indexArray->remove(indexArray->indexOf(my_table->currentColumn()));
//        QString str = "";

//        for (int i = 0;i<indexArray->size(); i++){
//            str += QString::number((*indexArray)[i])+" ";
//        }
//        label->setText(str);
//    }

//}

//void Widget::add_slot(){
//    if(!indexArray->contains(my_table->currentColumn())){
//        indexArray->append(my_table->currentColumn());
//        QString str = "Сортируются по убывыванию: ";

//        for (int i = 0;i<indexArray->size(); i++){
//            str += QString::number((*indexArray)[i]+1)+" ";
//        }
//        str+="\nСортируются по возростанию: ";
//        for (int i = 0;i<3;i++)
//            if (!indexArray->contains(i)){
//                str+=QString::number(i+1)+" ";
//            }

//        label->setText(str);
//    }

//}

void Widget::bubbleSort() {

    QVector<int> *indexArray = new QVector<int>();

    for (int i = 0; i < my_table->selectedItems().length(); i++) {

        if (!indexArray->contains(my_table->selectedItems()[i]->column())) {
        }
        {
            indexArray->append(my_table->selectedItems()[i]->column());
        }
    }

    for (int k = 0; k < 3; k++) {
        if (indexArray->contains(k)) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 9; j++) {

                    if ((*my_array)[k][j] < (*my_array)[k][j + 1]) {
                        int temp = (*my_array)[k][j];
                        (*my_array)[k][j] = (*my_array)[k][j + 1];
                        (*my_array)[k][j + 1] = temp;
                    }
                }
            }
        } else {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 9; j++) {

                    if ((*my_array)[k][j] > (*my_array)[k][j + 1]) {
                        int temp = (*my_array)[k][j];
                        (*my_array)[k][j] = (*my_array)[k][j + 1];
                        (*my_array)[k][j + 1] = temp;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {

            QTableWidgetItem
                    *newItem = new QTableWidgetItem(tr("%1").arg((*my_array)[i][j]));
            if ((*my_array)[i][j] < 0) {
                newItem->setBackground(Qt::red);
            } else {
                newItem->setBackground(Qt::green);
            }
            my_table->setItem(j, i, newItem);
        }
    }
}

void Widget::setTableValues() {
    my_array->erase(my_array->begin(), my_array->end());
    for (int i = 0; i < 3; i++) {
        QVector<int> tempVector;
        for (int j = 0; j < 10; j++) {
            int temp = QRandomGenerator::global()->bounded(-100, 100);
            tempVector.append(temp);
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(temp));
            if (temp < 0) {
                newItem->setBackground(Qt::red);
            } else {
                newItem->setBackground(Qt::green);
            }
            my_table->setItem(j, i, newItem);
        }
        my_array->append(tempVector);
    }
    bubbleSortButton->setEnabled(true);
    //    qDebug()<<*my_array;
}

Widget::~Widget() {
}

