#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->All_good->setHidden(true);
    ui->All_Good_label->setHidden(true);
    on_comboBox_currentIndexChanged(0);
    //ui->textBrowser->set
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gen_text()
{
    task="";
    time_t t=time(NULL);
    std::mt19937 gen(t);
    for(int i=0;i<size;i++)
    {
        QChar g=alphabet[language][gen()%alphabet[language].size()];
        if(g==' '&&task.size()>0&&task.back()==' ')
        {
            i--;
            continue;
        }
        task+=g;

    }
    ui->textBrowser->setText(task);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index!=0)return;
    language=index;
    gen_text();
    change_keyboard();
    update();
}

void MainWindow::change_keyboard()
{
    switch(language)
    {
    case 0:
        set_belarusian_keyboard();
        break;
    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;
    }
}

void MainWindow::set_belarusian_keyboard()
{
    ui->TildaButton->setText("Ё");
    ui->QButton->setText("Й");
    ui->WButton->setText("Ц");
    ui->EButton->setText("У");
    ui->RButton->setText("К");
    ui->TButton->setText("Е");
    ui->YButton->setText("Н");
    ui->UButton->setText("Г");
    ui->IButton->setText("Ш");
    ui->OButton->setText("Ў");
    ui->PButton->setText("З");
    ui->P1Button->setText("Х");
    ui->P2Button->setText("");
    ui->AButton->setText("Ф");
    ui->SButton->setText("Ы");
    ui->DButton->setText("В");
    ui->FButton->setText("А");
    ui->GButton->setText("П");
    ui->HButton->setText("Р");
    ui->JButton->setText("О");
    ui->KButton->setText("Л");
    ui->LButton->setText("Д");
    ui->L1Button->setText("Ж");
    ui->L2Button->setText("Э");
    ui->ZButton->setText("Я");
    ui->XButton->setText("Ч");
    ui->CButton->setText("С");
    ui->VButton->setText("М");
    ui->BButton->setText("І");
    ui->NButton->setText("Т");
    ui->MButton->setText("Ь");
    ui->M1Button->setText("Б");
    ui->M2Button->setText("Ю");
    ui->M3Button->setText("");
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton->setHidden(true);
    update();
    gen_text();
    ui->pushButton->setHidden(false);
    ui->pushButton->setEnabled(true);
    update();

}

