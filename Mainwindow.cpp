#include "Mainwindow.h"
#include "QVBoxLayout"
#include "QFileDialog"
#include "QLabel"
#include "QWidget"
#include "iostream"
#include "FrequenceButton.h"
#include "QVariant"
#include "controller.h"

MainWindow::MainWindow() : QWidget()
{
    setFixedSize(600, 450);
    this->defaultInitialization();
}

void MainWindow::defaultInitLayout()
{
    this->vLayout = new QVBoxLayout;
}

void MainWindow::defaultInitTitle()
{
    this->title = new QLabel("Veuillez séléctionner une fréquence");
    this->title->setAlignment(Qt::AlignCenter);
    this->vLayout->addWidget(this->title);
}

void MainWindow::defaultInitFreqButtons()
{
    for (int i = 0; i < 6; i++)
    {
        QVariant id(i);
        this->frequencyButtons[i] = new FrequenceButton(this->frequencyValues[i]);

        this->frequencyButtons[i]->setText(this->frequencyNames[i]);
        this->frequencyButtons[i]->setCursor(Qt::PointingHandCursor);
        this->frequencyButtons[i]->setProperty("id", id);

        this->vLayout->addWidget(this->frequencyButtons[i]);
        QObject::connect(this->frequencyButtons[i], SIGNAL(clicked()), this, SLOT(selectFile()));
    }
}

void MainWindow::defaultInitExitButton()
{
    this->exitButton = new QPushButton("Quitter", this);
    this->exitButton->setStyleSheet("background-color : red;");
    this->vLayout->addWidget(this->exitButton);
    QObject::connect(this->exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MainWindow::defaultInitialization()
{
    this->defaultInitLayout();
    this->defaultInitTitle();
    this->defaultInitFreqButtons();
    this->defaultInitExitButton();
    this->setLayout(this->vLayout);
}

void MainWindow::selectFile()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select a txt file"), tr("Text files(*.txt"));

    QString dirPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                        "/home",
                                                        QFileDialog::ShowDirsOnly
                                                        | QFileDialog::DontResolveSymlinks);

    postTraitement(filename.toStdString(), this->sender()->property("id").toInt(), dirPath.toStdString());
}
