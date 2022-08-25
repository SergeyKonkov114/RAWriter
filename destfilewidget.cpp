#include "destfilewidget.h"
#include <QHBoxLayout>
#include <QMessageBox>

DestinationFileWidget::DestinationFileWidget(QWidget *parent) : QWidget(parent) {

    //ComboBox with usb-devices
    selectUsbDeviceComboBox = new QComboBox(this);
    QStringList devices = getVolumes(QDir::drives());
    selectUsbDeviceComboBox->addItems(devices);

    destinationFilePath = selectUsbDeviceComboBox->currentText();

    //Unmount button
    QPushButton *unmountBtn = new QPushButton("Размонтировать", this);

    //Layout
    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->addWidget(selectUsbDeviceComboBox, 0);
    hbox->addWidget(unmountBtn, 0);
    setLayout(hbox);

    //Connections
    connect(unmountBtn, &QPushButton::clicked, this, &DestinationFileWidget::onClickUnmountBtn);
    connect(selectUsbDeviceComboBox, &QComboBox::textActivated, this, &DestinationFileWidget::setDestinationFilePath);
}

void DestinationFileWidget::onClickUnmountBtn() {
   QMessageBox::information(this, "RAWriter (ИПФ РАН)", "Данный функционал пока не доступен");
}

void DestinationFileWidget::setDestinationFilePath(const QString& destPath) {
    destinationFilePath = destPath;
}

QString DestinationFileWidget::getDestinationFilePath() const {
    return destinationFilePath;
}

QStringList getVolumes(const QFileInfoList& infoList) {
    QStringList volumes = {};
    foreach (const QFileInfo& fileInfo, infoList) {
        volumes.append(fileInfo.absoluteFilePath());
    }
    return volumes;
}
