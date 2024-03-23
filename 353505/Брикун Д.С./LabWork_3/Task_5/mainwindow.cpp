#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void count(const QDir& dir, unsigned long long & fileCount, unsigned long long & dirCount) {
    QFileInfoList entries = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo& entry : entries) {
        if (entry.isDir()) {
            ++dirCount;
            QDir subDir(entry.filePath());
            count(subDir, fileCount, dirCount);
        } else if (entry.isFile()) {
            ++fileCount;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString directoryPath = QFileDialog::getExistingDirectory(nullptr, "Выберите директорию", QDir::homePath());
    QDir path(directoryPath);
    if (path.exists()){
        ui->label_sf->setText("Processing...");
        ui->label_files->setText("Processing...");
        QCoreApplication::processEvents();
        unsigned long long d = 0, f = 0;

        count(path, f, d);
        ui->label_sf->setText(QString::number(d) + " SubFolders");
        ui->label_files->setText(QString::number(f) + " Files");
    }
}

