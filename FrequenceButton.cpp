#include "FrequenceButton.h"
#include <QWidget>
#include <QPushButton>

FrequenceButton::FrequenceButton(int frequence) : frequence(frequence) {}

int FrequenceButton::getFrequence() {

    return this->frequence;
}

void FrequenceButton::setFrequence(int frequence) {

    this->frequence = frequence;
}
