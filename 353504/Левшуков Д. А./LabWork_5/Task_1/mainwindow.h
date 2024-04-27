#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QKeyEvent>


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

    //Virtual keyboard methods
    void setBelarussian();
    QPushButton* getButton(int ind);
    void clearKeyboard();
    int key_to_ind(int key);


private slots:
    //Physic keyboard methods
    virtual void keyReleaseEvent(QKeyEvent *ke) override;
    virtual void keyPressEvent(QKeyEvent *ke) override;

    void on_comboBox_currentIndexChanged(int index);//Change language
    void on_checkBox_stateChanged(int arg1);//Hide useless button

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
