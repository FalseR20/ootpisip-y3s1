#pragma once

#include <QLineEdit>
#include <QPushButton>
#include "TaskWidget.hpp"


class Task2: public TaskWidget {
    QLineEdit *lineEdit;
    QPushButton *runButton;

public:
    Task2(QWidget *parent = nullptr);
};
