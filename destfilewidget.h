#pragma once

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QDir>

class DestinationFileWidget: public QWidget {
public:
    DestinationFileWidget(QWidget *parent = 0);
private slots:
    void onClickUnmountBtn();
    void setDestinationFilePath(const QString& destPath);
public:
    QString getDestinationFilePath() const;
private:
    QComboBox *selectUsbDeviceComboBox;
    QPushButton *unmountBtn;
    QString destinationFilePath;
};

QStringList getVolumes(const QFileInfoList& infoList);
