#pragma once
#include <QMainWindow>
#include <QLineEdit>
#include <srcfilewidget.h>
#include <destfilewidget.h>
#include <progressbarwidget.h>

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = 0);
private slots:
    void startCopy();
    void cancelCopy();
private:
    SourceFileWidget *sourceWidget;
    DestinationFileWidget *destinationWidget;
    ProgressBarWidget *progressWidget;
    QPushButton *startCopyBtn;
    QPushButton *cancelCopyBtn;
};
