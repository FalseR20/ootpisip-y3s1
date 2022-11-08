#include "ColorChanger.hpp"


ColorChanger::ColorChanger(const QString& color, QWidget *parent): QWidget(parent) {
    this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    label = new QLabel(color, this);
    label->setFixedWidth(50);
    spinBox = new QSpinBox(this);
    slider = new QSlider(Qt::Orientation::Horizontal, this);
    spinBox->setRange(0, 255);
    spinBox->setEnabled(false);
    slider->setRange(0, 255);
    QObject::connect(slider, &QSlider::sliderMoved, [=](int value) { spinBox->setValue(value); });

    layout = new QHBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(spinBox);
    layout->addWidget(slider);
}

//ColorChanger::~ColorChanger() {
//    delete label;
//    delete spinBox;
//    delete slider;
//    delete layout;
//}
