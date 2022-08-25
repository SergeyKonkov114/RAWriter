#pragma once

#include <QString>
#include <QFile>

class FileCopier : public QObject {
    Q_OBJECT
public:
    FileCopier(const QString& srcPath, const QString& destPath, QObject *parent = 0);
public:
    void startCopy();
    void setSourcePath(const QString& srcPath);
    void setDestinationPath(const QString& destPath);
signals:
    void copyProgressChanged(qint64 progress);
private:
    void prepareSourceFile(QFile& file);
    void prepareDestinationFile(QFile& file);
private:
    QString sourcePath;
    QString destinationPath;
};
