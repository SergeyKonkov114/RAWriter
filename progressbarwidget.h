#pragma once

#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include "filecopier.h"

class ProgressBarWidget : public QWidget {
public:
    ProgressBarWidget (const QString& srcPath = "", const QString& destPath = "", QWidget *parent = 0);
    void setSourcePath(const QString& srcPath);
    void setDestinationPath(const QString& destPath);
    void startCopy();
private slots:
    void updateBar(qint64 new_progress);
private:
    int progress;
    QProgressBar *pbar;
    FileCopier *fileCopier;
};
