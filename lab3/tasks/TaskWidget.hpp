#pragma once

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QGroupBox>


class TaskWidget: public QGroupBox {
    QLabel *descriptionLabel;

public:
    TaskWidget(QString description, QWidget *parent = nullptr);
};
