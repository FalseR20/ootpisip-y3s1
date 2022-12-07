#pragma once

#include <QLineEdit>
#include <QPushButton>
#include "TaskWidget.hpp"


class AdditionalTask: public TaskWidget {
    QLineEdit *lineEdit;
    QPushButton *runButton;

public:
    explicit AdditionalTask(QWidget *parent = nullptr);
};
