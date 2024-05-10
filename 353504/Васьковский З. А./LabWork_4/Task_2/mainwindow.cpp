#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainUpdating = new bool;
    *mainUpdating = false;


    toolBar->setParent(this);
    toolBar->setGeometry(1450, 0, 300 ,1500); // Установка размеров и положения toolBar

    sortButton->setParent(toolBar);
    sortButton->setGeometry(10, 10, 280, 30); // Расположение кнопки с учетом отступов и размеров
    sortButton->setText("Выполнить сортировку");

    searchButton->setParent(toolBar);
    searchButton->setGeometry(10, 50, 280, 30); // Расположение кнопки с учетом отступов и размеров
    searchButton->setText("Найти элемент");

    quantityTextEdit->setParent(toolBar);
    quantityTextEdit->setText("Введите количество элементов");
    quantityTextEdit->setGeometry(10, 90, 280, 30); // Расположение текстового поля с учетом отступов и размеров

    sizeSpinBox->setParent(toolBar);
    sizeSpinBox->setRange(1,100);
    sizeSpinBox->setGeometry(10, 130, 280, 30); // Расположение спинбокса с учетом отступов и размеров

    timeLabel->setParent(toolBar);
    timeLabel->setGeometry(10, 170, 280, 30); // Расположение надписи с учетом отступов и размеров
    timeLabel->setText("Затраченное время:");

    findLabel->setParent(toolBar);
    findLabel->setGeometry(10, 210, 280, 30); // Расположение надписи с учетом отступов и размеров
    findLabel->setText("Выберите элемент для поиска:");

    findSpinBox->setParent(toolBar);
    findSpinBox->setRange(1,100);
    findSpinBox->setGeometry(10, 250, 280, 30); // Расположение спинбокса с учетом отступов и размеров

    ansFindLabel->setParent(toolBar);
    ansFindLabel->setGeometry(10, 290, 280, 30); // Расположение надписи с учетом отступов и размеров
    ansFindLabel->setText("Индекс элемента:");

    powLabel->setParent(toolBar);
    powLabel->setGeometry(10, 330, 280, 30); // Расположение надписи с учетом отступов и размеров
    powLabel->setText("Результат возведения в степень:");





    timer = new QTimer();
    connect(timer, &QTimer::timeout, [&](){
        update();
        sortButton->setEnabled(!*mainUpdating);
        sortButton->setPalette(QPalette((!*mainUpdating)? Qt::white : Qt::gray));
        sizeSpinBox->setEnabled(!*mainUpdating);
        sizeSpinBox->setPalette(QPalette((!*mainUpdating)? Qt::white : Qt::gray));

        if (isSort()){
            searchButton->setEnabled(!*mainUpdating);
            searchButton->setPalette(QPalette((!*mainUpdating)? Qt::white : Qt::gray));
        }
        else{
            searchButton->setEnabled(false);
            searchButton->setPalette(QPalette(Qt::gray));
        }

        if (size != sizeSpinBox->value() && !*mainUpdating){
            size = sizeSpinBox->value();
            createNewArr();
        }

    });
    timer->start(30);

    QPushButton::connect(sortButton, SIGNAL(pressed()), this, SLOT(on_sortButton_clicked()));
    QPushButton::connect(searchButton, SIGNAL(pressed()), this, SLOT(on_searchButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::randomNumberGenerate()
{
    QRandomGenerator rand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QVector<int> randomNumbers;
    for (int i = 0; i < sizeSpinBox->value(); ++i) {
        int randomNum = rand.bounded(1, 101);
        while (randomNumbers.contains(randomNum)) {
            randomNum = rand.bounded(1, 101);
        }
        randomNumbers.append(randomNum);
        arr[i] = randomNumbers[i];
    }


}

void MainWindow::showSort()
{
    int* i = new int;
    *i = 0;
    QTimer* thisTimer = new QTimer();
    thisTimer->start();
    *mainUpdating = true;
    QElapsedTimer startTime;
    startTime.start();
    connect(thisTimer, &QTimer::timeout, [=](){
        if (*i < arr.size()){
            RectsVector[*i]->setHeight(20 + 13 * arr[*i]);
            (*i)++;
        }
        else{
            *mainUpdating = false;
            thisTimer->stop();
            ind1 = ind2 = -1;
            timeLabel->setText("Затраченное время: " + QString::number(startTime.elapsed()));
        }
    });
    thisTimer->setInterval(30);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    for (int i = 0; i < RectsVector.size(); ++i){
        if (i == ind1 || i == ind2) paint.setBrush(Qt::black);
        else paint.setBrush(Qt::white);
        paint.drawRect(*RectsVector[i]);
    }
}

void MainWindow::createNewArr()
{
    ansFindLabel->setText("");
    timeLabel->setText("");
    ind1 = -1;
    ind2 = -1;

    arr = QVector<int>(sizeSpinBox->value());
    for (int i = 0; i < RectsVector.size(); ++i){
        delete RectsVector[i];
    }
    RectsVector.clear();
    motionVector.clear();
    randomNumberGenerate();
    for (int i = 0; i < sizeSpinBox->value(); ++i){
        QRectF *rect = new QRectF(30 + 10 * i, 20, 10, 20 + 13 * arr[i]);
        RectsVector.append(rect);
    }

}

bool MainWindow::isSort()
{
    for (int i = 1; i < arr.size(); ++i){
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int MainWindow::binsearch(int digit)
{
    ind1 = 0;
    ind2 = sizeSpinBox->value() - 1;
    if (arr[ind1] > digit || arr[ind2] < digit) return -1;
    while (ind1 <= ind2){
        int mid = ind1 + (ind2 - ind1) / 2;
        if (arr[mid] == digit){
            ind1 = mid;
            ind2 = mid;
            return mid;
        }
        if (arr[mid] < digit) ind1 = mid +1;
        else ind2 = mid - 1;
    }

    ind1 = -1;
    ind2 = -1;
    return -1;
}

int MainWindow::binpow(int digit, int powder, int mod)
{
    if (powder == 0) return 1;
    unsigned long int z = binpow(digit % mod, powder / 2, mod) % mod;
    if (powder % 2 == 0)
        return (z * z) % mod;
    else
        return ((digit % mod) * ((z * z) % mod)) % mod;
}

void MainWindow::on_sortButton_clicked()
{

    if (!isSort()){
        InterpoliationSort::interpolationSort(arr, motionVector);
        showSort();
    }
    else QMessageBox::information(this, "Внимание", "Массив и так отсортирован");

}

void MainWindow::on_searchButton_clicked()
{
    int index = binsearch(findSpinBox->value());
    ansFindLabel->setText("Индекс элемента: " + QString::number(index));
    if (index != -1) powLabel->setText("Результат возведения в степень: " + QString::number(binpow(index, sizeSpinBox->value(), arr[index])));

}
