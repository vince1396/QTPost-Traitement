#ifndef FREQUENCEBUTTON_H
#define FREQUENCEBUTTON_H

#include<QPushButton>

class FrequenceButton : public QPushButton {

    public:

    FrequenceButton(int frequence);
    int getFrequence();
    void setFrequence(int frequence);

    private:

    int frequence;
};

#endif // FREQUENCEBUTTON_H
