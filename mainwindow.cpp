#include "mainwindow.h"
#include <QLabel>
#include <QFormLayout>
#include <QTextStream>

#include <QDir>
#include <QStorageInfo>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    QTextStream out(stdout);

    setWindowTitle("RAWriter (ИПФ РАН)");

    //Labels
    QLabel *selectFileLabel = new QLabel("Выбрать файл:", this);
    QLabel *selectUsbDeviceLbl = new QLabel("Выбрать USB-устройство:", this);

    //Source File Widget
    sourceWidget = new SourceFileWidget(this);

    //Destination File Widget
    destinationWidget = new DestinationFileWidget(this);

    //Progress Bar Widget
    progressWidget = new ProgressBarWidget("", "", this);
    startCopyBtn = new QPushButton("Начать", this);
    cancelCopyBtn = new QPushButton("Отмена", this);
    cancelCopyBtn->setEnabled(false);

    //Layout    
    QFrame *frame = new QFrame(this);
    setCentralWidget(frame);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->addRow(selectFileLabel, sourceWidget);
    formLayout->addRow(selectUsbDeviceLbl, destinationWidget);

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->addWidget(progressWidget);
    hbox->addWidget(startCopyBtn);
    hbox->addWidget(cancelCopyBtn);

    QVBoxLayout *vbox = new QVBoxLayout(frame);
    vbox->addLayout(formLayout);
    vbox->addLayout(hbox);
    vbox->addStretch();

    connect(startCopyBtn, &QPushButton::clicked, this, &MainWindow::startCopy);
}

void MainWindow::startCopy() {
    startCopyBtn->setEnabled(false);
    cancelCopyBtn->setEnabled(true);

    QString sourcePath = sourceWidget->getSourceFilePath();
    QString destinationPath = destinationWidget->getDestinationFilePath();
    destinationPath += sourceWidget->getSourceFileName();

    progressWidget->setSourcePath(sourcePath);
    progressWidget->setDestinationPath(destinationPath);
    progressWidget->startCopy();

    startCopyBtn->setEnabled(true);
    cancelCopyBtn->setEnabled(false);
}



