#pragma once

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QGroupBox>


class TaskWidget: public QGroupBox {
    QLabel *descriptionLabel;

protected:
    QWidget *runWidget;

public:
    QString labelText;

    explicit TaskWidget(QString description, QWidget *parent = nullptr);
};
