#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ctime>
#include <random>

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
private slots:
    void on_comboBox_currentIndexChanged(int index);

    void change_keyboard();
    void set_belarusian_keyboard();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    const int size=1500;//size of text_browser
    const QString alphabet[2]={"йцукенгшўзхфывапролджэячсмітьбю ","aa"};//0-Belarusian
    QString task;
    int language=0;

};
#endif // MAINWINDOW_H
