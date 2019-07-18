#ifndef DEF_MAINWINDOW
#define DEF_MAINWINDOW

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
    MainWindow();

    public slots:
    void changeWidth(int width);

    private:
    QWidget *fenetre;
    QVBoxLayout *vLayout;

    QPushButton *boutonExit;
    QPushButton *bouton800;
    QPushButton *bouton900;
    QPushButton *bouton1800;
    QPushButton *bouton2100;
    QPushButton *bouton2300;
    QPushButton *bouton2600;
};

#endif
