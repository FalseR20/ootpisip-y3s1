#include "ColorChanger.hpp"


ColorChanger::ColorChanger(const QString &color, QWidget *parent) : QWidget(parent) {
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    layout = new QHBoxLayout(this);

    label = new QLabel(color, this);
    layout->addWidget(label);
    label->setFixedWidth(50);

    spinBox = new QSpinBox(this);
    layout->addWidget(spinBox);
    spinBox->setRange(0, 255);
    spinBox->setEnabled(false);

    slider = new QSlider(Qt::Orientation::Horizontal, this);
    layout->addWidget(slider);
    slider->setRange(0, 255);
    QObject::connect(slider, &QSlider::sliderMoved, [=](int value) { spinBox->setValue(value); });
}
