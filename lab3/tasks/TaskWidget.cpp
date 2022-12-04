#include "TaskWidget.hpp"


TaskWidget::TaskWidget(QString description, QWidget *parent): QGroupBox(parent) {
    setLayout(new QVBoxLayout(this));

    descriptionLabel = new QLabel(description, this);
    descriptionLabel->setFont(QFont("", 12));
    layout()->addWidget(descriptionLabel);
    layout()->setAlignment(Qt::Alignment(Qt::AlignTop));
    this->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
}
