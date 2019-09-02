#ifndef DEF_MAINWINDOW
#define DEF_MAINWINDOW

#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <FrequenceButton.h>

class MainWindow : public QWidget
{
    Q_OBJECT

    // =======================================================
    public:

    const QString frequencyNames[6] = {"F800", "F900", "F1800", "F2100", "F2300", "F2600"};
    const int frequencyValues[6] = {800, 900, 1800, 2100, 2300, 2600};

    MainWindow();

    // =======================================================
    public slots:

    void selectFile();

    // =======================================================
    signals:

    void identified(int frequence);

    // =======================================================
    private:

    QVBoxLayout *vLayout;
    QLabel *title;
    QPushButton *exitButton;
    FrequenceButton *frequencyButtons[6];

    void removeFrequencyButton(int i);
    void defaultInitLayout();
    void defaultInitTitle();
    void defaultInitFreqButtons();
    void defaultInitExitButton();
    void defaultInitialization();
};

#endif
