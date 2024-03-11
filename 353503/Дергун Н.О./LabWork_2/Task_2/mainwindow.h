#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSet>
#include <QTableWidget>
#include "patientlist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSet<unsigned> returnSet, filteredSet;
    QVector<unsigned> filteredVector;
    const long long wardNumber = 10;

    PatientList* patientList, *saveList;
    QVector<Patient> patientVector;
    //const QString exampleFileName = "B:/Qt_Projects/Task2/exampledate.bin";
    QString currentFileName, saveFileName;

    short getMode();
    void updateTable();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotApply();
    void slotChangePatient();
    void slotModeChanged();
    void slotOpenFile();
    void slotSaveFile();
    void slotSortWards();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
