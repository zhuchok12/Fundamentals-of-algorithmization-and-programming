#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ctime>
#include <random>
#include <QKeyEvent>
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
    void gen_text();
    bool index_of_button(int& ind,int b);
    QPushButton* get(int index);
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void change_keyboard();
    void set_belarusian_keyboard();
    void on_pushButton_clicked();
    virtual void keyReleaseEvent(QKeyEvent *ke) override;
    virtual void keyPressEvent(QKeyEvent *ke) override;
    void PercentOfText();
    void SetTime();
    void Start();
    // /pus
private:
    Ui::MainWindow *ui;
    const int size=1000;//size of text_browser
    const QString alphabet[2]={"ёйцукенгшўзхфывапролджэячсмітьбюЁЙЦУКЕНГШЎЗХФЫВАПРОЛДЖЭЯЧСМІТЬБЮ                                     ","aa"};//0-Belarusian
    const int toUp[2]={std::string("ёйцукенгшўзхфывапролджэячсмітьбю").size()/2,0};
    QString task;
    int language=0;
    const int but[38]={96, 81, 87, 69, 82, 84, 89, 85, 73, 79, 80, 91, 93, 65, 83, 68, 70, 71, 72, 74, 75, 76, 59, 39, 90, 88, 67, 86, 66, 78, 77, 44, 46, 47, 16777252, 16777248, 32, 16777219};//Last 4: caps shift space backspace
    time_t start;
    //Stylsheets
    const QString default_button="background-color: rgb(143, 240, 164);color: rgb(0, 0, 0);";
    const QString pressed_button="background-color: rgb(246, 97, 81);color: rgb(0, 0, 0);";

};
#endif // MAINWINDOW_H
