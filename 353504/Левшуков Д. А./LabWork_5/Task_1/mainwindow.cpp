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
    SetDefaultKeyboard();
    qDebug()<<toUp[0];
    ui->BackSpaceButton->setHidden(true);
    ui->PercentOfText->setValue(0);
    ui->Accurate->setValue(0);
    on_checkBox_stateChanged(0);
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

    while(task.back()==' ')// space in the end
    {
        task.back()=alphabet[language][gen()%alphabet[language].size()];
    }
    ui->textBrowser->setText(task);
}


bool MainWindow::index_of_button(int &ind,int b)
{
    for(int i=0;i<39;i++)
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
        return ui->MinusButton;
    if(index==but[35])
        return ui->CapsButton;
    if(index==but[36])
        return ui->ShiftButton;
    if(index==but[37])
        return ui->SpaceButton;
    if(index==but[38])
        return ui->BackSpaceButton;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    //qDebug()<<"Language changed:"<<index;
    if(index>1)return;
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
        set_german_keyboard();
        break;

    case 2:
    {

        break;
    }
    case 3:
        break;

    case 4:
        break;

    case 5:
        break;
    }
    if(!Hiden)
        ShowUnusedKeys();
    else
        HideUnusedKeys();
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
    ui->MinusButton->setText("");
    //qDebug()<<ui->M3Button->text();
    update();
}

void MainWindow::set_german_keyboard()
{
    ui->TildaButton->setText("");
    ui->QButton->setText("Q");
    ui->WButton->setText("W");
    ui->EButton->setText("E");
    ui->RButton->setText("R");
    ui->TButton->setText("T");
    ui->YButton->setText("Z");
    ui->UButton->setText("U");
    ui->IButton->setText("I");
    ui->OButton->setText("O");
    ui->PButton->setText("P");
    ui->P1Button->setText("Ü");
    ui->P2Button->setText("");
    ui->AButton->setText("A");
    ui->SButton->setText("S");
    ui->DButton->setText("D");
    ui->FButton->setText("F");
    ui->GButton->setText("G");
    ui->HButton->setText("H");
    ui->JButton->setText("J");
    ui->KButton->setText("K");
    ui->LButton->setText("L");
    ui->L1Button->setText("Ö");
    ui->L2Button->setText("Ä");
    ui->ZButton->setText("");
    ui->XButton->setText("Y");
    ui->CButton->setText("X");
    ui->VButton->setText("C");
    ui->BButton->setText("V");
    ui->NButton->setText("B");
    ui->MButton->setText("N");
    ui->M1Button->setText("M");
    ui->M2Button->setText("");
    ui->M3Button->setText("");
    ui->MinusButton->setText("ß");
    //qDebug()<<ui->M3Button->text();
    update();
}

void MainWindow::set_french_keyboard()
{

    ui->TildaButton->setText("");
    ui->QButton->setText("A");
    ui->WButton->setText("Z");
    ui->EButton->setText("E");
    ui->RButton->setText("R");
    ui->TButton->setText("T");
    ui->YButton->setText("Z");
    ui->UButton->setText("U");
    ui->IButton->setText("I");
    ui->OButton->setText("O");
    ui->PButton->setText("P");
    ui->P1Button->setText("Ü");
    ui->P2Button->setText("");
    ui->AButton->setText("A");
    ui->SButton->setText("S");
    ui->DButton->setText("D");
    ui->FButton->setText("F");
    ui->GButton->setText("G");
    ui->HButton->setText("H");
    ui->JButton->setText("J");
    ui->KButton->setText("K");
    ui->LButton->setText("L");
    ui->L1Button->setText("Ö");
    ui->L2Button->setText("Ä");
    ui->ZButton->setText("");
    ui->XButton->setText("Y");
    ui->CButton->setText("X");
    ui->VButton->setText("C");
    ui->BButton->setText("V");
    ui->NButton->setText("B");
    ui->MButton->setText("N");
    ui->M1Button->setText("M");
    ui->M2Button->setText("");
    ui->M3Button->setText("");
    ui->MinusButton->setText("ß");
    //qDebug()<<ui->M3Button->text();
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

void MainWindow::PercentOfText()
{

}


void MainWindow::SetTime()
{
    ui->Time->setText(QString::fromStdString(std::to_string(clock()-start)));
}


void MainWindow::Start()
{
    ui->PercentOfText->setValue(0);
    ui->Accurate->setValue(0);
    start=clock();
    ui->speed->setText("");
}

void MainWindow::SetDefaultKeyboard()
{
    for(int i=0;i<39;i++)
    {
        get(but[i])->setStyleSheet(default_button);
        get(but[i])->setFocusPolicy(Qt::NoFocus);
    }
    CapsActive=false;
}

void MainWindow::ChangeCapsState()
{
    if(CapsActive)
        CapsActive=false;
    else CapsActive=true,ui->CapsButton->setStyleSheet(CapsOn);

}


void MainWindow::keyReleaseEvent(QKeyEvent *ke)
{
    int key=ke->key();
    int ind=0;
    if(!index_of_button(ind,key))return;

    get(key)->setStyleSheet(default_button);
    if(ke->key()==16777252)
        ChangeCapsState();
    else
        qDebug()<<"-"<<ke->key()<<" "<<key;
}

void MainWindow::on_checkBox_stateChanged(int arg1)//0 - no 2- yes
{
    ShowUnusedKeys();
    if(arg1==0)
    {
        HideUnusedKeys();
        Hiden=true;
    }
    else
    {

        Hiden=false;
    }

    //qDebug()<<arg1;
}

void MainWindow::HideUnusedKeys()
{
    ShowUnusedKeys();
    for(int i=0;i<36;i++)
    {
        //qDebug()<<get(but[i])->text();
        if(get(but[i])->text()=="")
            get(but[i])->setHidden(true);
    }
}

void MainWindow::ShowUnusedKeys()
{
    for(int i=0;i<36;i++)
    {
        //if(get(b[i])->text()=="")
            get(but[i])->setHidden(false);
    }
}
