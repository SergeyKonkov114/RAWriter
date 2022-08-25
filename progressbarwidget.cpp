#include "progressbarwidget.h"
#include <QHBoxLayout>

ProgressBarWidget::ProgressBarWidget (const QString& srcPath, const QString& destPath, QWidget *parent) : QWidget(parent) {

    progress = 0;
    pbar = new QProgressBar(this);
    fileCopier = new FileCopier(srcPath, destPath, this);
    connect(fileCopier, &FileCopier::copyProgressChanged, this, &ProgressBarWidget::updateBar);
}

void ProgressBarWidget::setSourcePath(const QString& srcPath) {
    fileCopier->setSourcePath(srcPath);
}

void ProgressBarWidget::setDestinationPath(const QString& destPath) {
    fileCopier->setDestinationPath(destPath);
}

void ProgressBarWidget::updateBar(qint64 new_progress) {
    pbar->setValue(new_progress);
}

void ProgressBarWidget::startCopy() {
    pbar->setValue(0);
    fileCopier->startCopy();
}
