#pragma once

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>


class ColorChanger : public QWidget {
    QLabel *label;
    QSpinBox *spinBox;
    QHBoxLayout *layout;
public:
    QSlider *slider;

    explicit ColorChanger(const QString &color, QWidget *parent = nullptr);

//    ~ColorChanger() override;
};
