#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

unsigned long long MainWindow::countFolders(const QString &directoryPath)
{
    unsigned long long foldersCount = 0;

    QDir directory(directoryPath);

    QFileInfoList allItems = directory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(const QFileInfo &item : allItems)
    {
        foldersCount += (1 + countFolders(item.filePath()));
    }

    return foldersCount;
}

unsigned long long MainWindow::countFiles(const QString &directoryPath)
{
    unsigned long long filesCount = 0;

    QDir directory(directoryPath);

    QFileInfoList allItems = directory.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);

    filesCount += allItems.size();

    for(const QFileInfo &item : allItems)
    {
        filesCount += countFiles(item.filePath());
    }

    return filesCount;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString directoryPath = QFileDialog::getExistingDirectory(this, tr("Choose Directory"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!directoryPath.isEmpty())
    {
        ui->lineFolders->setText(QString::number(countFolders(directoryPath)));
        ui->lineFiles->setText(QString::number(countFiles(directoryPath)));
    }
}
