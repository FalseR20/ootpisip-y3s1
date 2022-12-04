#pragma once

#include <QLineEdit>
#include <QPushButton>
#include "TaskWidget.hpp"


class Task1: public TaskWidget {
    QLineEdit *lineEdit;
    QPushButton *runButton;

public:
    Task1(QWidget *parent = nullptr);
};
