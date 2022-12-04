#include "TaskWidget.hpp"


TaskWidget::TaskWidget(QString description, QWidget *parent): QGroupBox(parent) {
    setLayout(new QVBoxLayout(this));

    descriptionLabel = new QLabel(description, this);
    descriptionLabel->setFont(QFont("", 12));
    runWidget = new QWidget(this);
    layout()->addWidget(descriptionLabel);
    layout()->addWidget(runWidget);
    this->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
}
