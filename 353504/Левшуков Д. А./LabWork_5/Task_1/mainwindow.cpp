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

    //Set base options of button
    for(int i=0;i<38;i++)
    {
        get(but[i])->setStyleSheet(default_button);
        get(but[i])->setFocusPolicy(Qt::NoFocus);
    }
    qDebug()<<toUp[0];
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
        if(g==' '&&task.size()>0&&task.back()==' ')//double space
        {
            i--;
            continue;
        }
        if(g==' '&&i==0)//space in begining
        {
            i--;
            continue;
        }
        task+=g;

    }
    ui->textBrowser->setText(task);
}

bool MainWindow::index_of_button(int &ind,int b)
{
    for(int i=0;i<38;i++)
        if(but[i]==b)
        {
            ind=i;
            return true;
        }
    return false;
}

QPushButton* MainWindow::get(int index)
{
    //qDebug()<<index<<" "<<but[36];
    if(index==but[0])
        return ui->TildaButton;
    if(index==but[1])
        return ui->QButton;
    if(index==but[2])
        return ui->WButton;
    if(index==but[3])
        return ui->EButton;
    if(index==but[4])
        return ui->RButton;
    if(index==but[5])
        return ui->TButton;
    if(index==but[6])
        return ui->YButton;
    if(index==but[7])
        return ui->UButton;
    if(index==but[8])
        return ui->IButton;
    if(index==but[9])
        return ui->OButton;
    if(index==but[10])
        return ui->PButton;
    if(index==but[11])
        return ui->P1Button;
    if(index==but[12])
        return ui->P2Button;
    if(index==but[13])
        return ui->AButton;
    if(index==but[14])
        return ui->SButton;
    if(index==but[15])
        return ui->DButton;
    if(index==but[16])
        return ui->FButton;
    if(index==but[17])
        return ui->GButton;
    if(index==but[18])
        return ui->HButton;
    if(index==but[19])
        return ui->JButton;
    if(index==but[20])
        return ui->KButton;
    if(index==but[21])
        return ui->LButton;
    if(index==but[22])
        return ui->L1Button;
    if(index==but[23])
        return ui->L2Button;
    if(index==but[24])
        return ui->ZButton;
    if(index==but[25])
        return ui->XButton;
    if(index==but[26])
        return ui->CButton;
    if(index==but[27])
        return ui->VButton;
    if(index==but[28])
        return ui->BButton;
    if(index==but[29])
        return ui->NButton;
    if(index==but[30])
        return ui->MButton;
    if(index==but[31])
        return ui->M1Button;
    if(index==but[32])
        return ui->M2Button;
    if(index==but[33])
        return ui->M3Button;
    if(index==but[34])
        return ui->CapsButton;
    if(index==but[35])
        return ui->ShiftButton;
    if(index==but[36])
        return ui->SpaceButton;
    if(index==but[37])
        return ui->BackSpaceButton;
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
    update();
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


void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    int key=ke->key();
    int ind=0;
    //qDebug()<<"+"<<ke->key();
    if(!index_of_button(ind,key))return;

    get(key)->setStyleSheet(pressed_button);
    qDebug()<<"+"<<ke->key();
}

void MainWindow::keyReleaseEvent(QKeyEvent *ke)
{
    int key=ke->key();
    int ind=0;
    if(!index_of_button(ind,key))return;

    get(key)->setStyleSheet(default_button);
    qDebug()<<"-"<<ke->key();
}
