#include <srcfilewidget.h>
#include <QHBoxLayout>
#include <QFileDialog>

SourceFileWidget::SourceFileWidget(QWidget *parent) : QWidget(parent) {

    //Select source file button
    selectFilePathBtn = new QPushButton("...", this);
    selectFilePathBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    selectFilePathBtn->setFixedWidth(40);

    //Source file path line edit
    filePathLineEdt = new QLineEdit(this);
    filePathLineEdt->setPlaceholderText("Выберите файл...");
    filePathLineEdt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    filePathLineEdt->setMinimumWidth(300);

    //Layout
    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->addWidget(filePathLineEdt, 0);
    hbox->addWidget(selectFilePathBtn, 0);
    setLayout(hbox);

    //Connections
    connect(selectFilePathBtn, &QPushButton::clicked, this, &SourceFileWidget::setSourceFilePath);
}

void SourceFileWidget::setSourceFilePath() {
    QString str = QFileDialog::getOpenFileName(0, "Выберите файл");
    filePathLineEdt->setText(str);
}

QString SourceFileWidget::getSourceFilePath() const {
    return filePathLineEdt->text();
}

QString SourceFileWidget::getSourceFileName() const {
    QFileInfo srcFileInfo(filePathLineEdt->text());
    return srcFileInfo.fileName();
}
