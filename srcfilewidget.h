#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class SourceFileWidget : public QWidget {
public:
    SourceFileWidget(QWidget *parent = 0);
private slots:
    void setSourceFilePath();
public:
    QString getSourceFilePath() const;
    QString getSourceFileName() const;
private:
    QPushButton *selectFilePathBtn;
    QLineEdit *filePathLineEdt;
};
