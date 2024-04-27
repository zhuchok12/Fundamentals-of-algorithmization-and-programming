#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setBelarussian();
    QPushButton* getButton(int ind);
    void clearKeyboard();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    //Stylsheets
    const QString default_button="background-color: rgb(143, 240, 164);color: rgb(0, 0, 0);";
    const QString pressed_button="background-color: rgb(246, 97, 81);color: rgb(0, 0, 0);";
    const QString CapsOn="background-color: rgb(248, 228, 92);color: rgb(0, 0, 0);";

    //Alphabet
    QString alphabet;
    const short int delta=46;//Upper+46==lower

    bool Shift_on,Caps_on;

};
#endif // MAINWINDOW_H
