#pragma once

#include <QLineEdit>
#include <QPushButton>
#include "TaskWidget.hpp"


class Task3: public TaskWidget {
    QPushButton *runButton;

public:
    explicit Task3(QWidget *parent = nullptr);
};
