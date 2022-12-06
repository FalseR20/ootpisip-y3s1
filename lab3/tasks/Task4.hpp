#pragma once

#include <QLineEdit>
#include <QPushButton>
#include "TaskWidget.hpp"


class Task4: public TaskWidget {
    QLineEdit *lineEdit;
    QPushButton *runButton;

public:
    Task4(QWidget *parent = nullptr);
};
