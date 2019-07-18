#include "mainwindow.h"
#include "QVBoxLayout"

MainWindow::MainWindow() : QWidget()
{
    setFixedSize(500, 350);

    // ============================================================================
    //QWidget fenetre;

    // LAYOUT
    vLayout = new QVBoxLayout;

    // BOUTON QUITTER
    boutonExit = new QPushButton("Quitter", this);
    boutonExit->setFont(QFont("Comic Sans MS", 14));
    boutonExit->setCursor(Qt::PointingHandCursor);
    boutonExit->move(400, 300);
    boutonExit->setStyleSheet("background-color: red;");

    // BOUTON FREQUENCE
    bouton800  = new QPushButton("F800");
    bouton900  = new QPushButton("F900");
    bouton1800 = new QPushButton("F1800");
    bouton2100 = new QPushButton("F2100");
    bouton2300 = new QPushButton("F2300");
    bouton2600 = new QPushButton("F2600");
    // ============================================================================

    // ============================================================================
    // LAYOUT BINDING

    vLayout->addWidget(bouton800);
    vLayout->addWidget(bouton900);
    vLayout->addWidget(bouton1800);
    vLayout->addWidget(bouton2100);
    vLayout->addWidget(bouton2300);
    vLayout->addWidget(bouton2600);
    vLayout->addWidget(boutonExit);

    this->setLayout(vLayout);
    // ============================================================================




    // ============================================================================
    // EVENTS

    QObject::connect(boutonExit, SIGNAL(clicked()), qApp, SLOT(quit()));
    //QWidget::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
    //QWidget::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changeWidth(int)));
    // ============================================================================
}

void MainWindow::changeWidth(int width)
{
    setFixedSize(width, 350);
}
