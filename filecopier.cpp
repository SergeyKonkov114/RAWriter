#include "filecopier.h"
#include <QFileInfo>

FileCopier::FileCopier(const QString& srcPath, const QString& destPath, QObject *parent) : QObject(parent) {
    sourcePath = srcPath;
    destinationPath = destPath;
}

void FileCopier::prepareSourceFile(QFile& file) {

    if (!file.exists()) {
        qWarning("The source file does not exist");
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Can not open source file for reading");
    }
}

void FileCopier::prepareDestinationFile(QFile& file) {

    if (file.exists()) {
        qWarning("File with same name already exist in destination folder");
    }

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Could not open destination file");
    }
}

void FileCopier::setSourcePath(const QString& srcPath) {
    sourcePath = srcPath;
}

void FileCopier::setDestinationPath(const QString& destPath) {
    destinationPath = destPath;
}

void FileCopier::startCopy() {

    QFile srcFile(sourcePath);
    prepareSourceFile(srcFile);
    QFile destFile(destinationPath);
    prepareDestinationFile(destFile);

    QFileInfo srcInfo(srcFile);
    qint64 srcFileSize = srcInfo.size();

    QByteArray buf = 0;
    const qint64 filePart = 1048576;  //1 Mb
    qint64 progress = 0;
    while (!(buf = srcFile.read(filePart)).isEmpty()) {
        destFile.write(buf);
        progress += buf.size();
        emit copyProgressChanged(progress * 100 / srcFileSize);
    }
}
