#include "mainwindow.h"
#include "ui_mainwindow.h"

int WIDTH1 = 0;
int WIDTH2 = 0;
int WIDTH3 = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(1);
    solver.Solve(ui->tableWidget, 0, 2, amOfMoves, 1);
    QHeaderView *header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::updateTable);
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::updateGraphics);
    //setLayout(ui->gridLayout);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    ster1 = new QGraphicsRectItem(QRectF(0, 0, 10, 400));
    ster2 = new QGraphicsRectItem(QRectF(350, 0, 10, 400));
    ster3 = new QGraphicsRectItem(QRectF(-350, 0, 10, 400));
    ster1->setBrush(QBrush(Qt::yellow));
    ster2->setBrush(QBrush(Qt::yellow));
    ster3->setBrush(QBrush(Qt::yellow));
    scene->addItem(ster1);
    scene->addItem(ster2);
    scene->addItem(ster3);

    updateGraphics();

    this->setWindowTitle("Ханойские башни");

    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, [&]{
        if (i >= ui->tableWidget->rowCount()) {
            ui->spinBox->setDisabled(false);
            animationTimer->stop();
            ui->pushButton->setDisabled(true);
            ui->pushButton->setText("начать");
           // ui->backButton->setDisabled(false);
          //  ui->forwardButton->setDisabled(true);
        }
        else {
            ui->tableWidget->selectRow(i);
            move.Moves(sterzhni, ui->tableWidget->item(i, 0)->text().at(0).toLatin1() - '1',
                       ui->tableWidget->item(i, 1)->text().at(0).toLatin1() - '1');
            i++;
        }
    });

    this->setFixedSize(this->size());

    ui->pushButton->setText("начать");

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);



    forwardTimer = new QTimer(this);
    connect(forwardTimer, &QTimer::timeout, [&]{
        forwardTimer->stop();
       // ui->forwardButton->setDisabled(false);
        ui->pushButton->setDisabled(false);

        if (i == ui->tableWidget->rowCount()) {
        //    ui->forwardButton->setDisabled(true);
            ui->pushButton->setDisabled(true);
        }
      //  ui->backButton->setDisabled(false);
    });

    backTimer = new QTimer(this);
    connect(backTimer, &QTimer::timeout, [&]{
        backTimer->stop();
       // ui->backButton->setDisabled(false);
        ui->pushButton->setDisabled(false);
        if (i == 0) {
       //     ui->backButton->setDisabled(true);
        }
       // ui->forwardButton->setDisabled(false);
    });

  //  ui->backButton->setDisabled(true);

    scene->setSceneRect(-525, -75, 1000, 550);

    ui->tableWidget->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateTable()
{
    ui->pushButton->setText("начать");
    ui->pushButton->setDisabled(false);
   // ui->forwardButton->setDisabled(false);
  //  ui->backButton->setDisabled(true);
    int pow2 = 1;
    for (int i = 0; i < ui->spinBox->value(); ++i) {
        pow2 *= 2;
    }
    ui->tableWidget->setRowCount(pow2 - 1);
    amOfMoves = 0;
    solver.Solve(ui->tableWidget, 0, 2, amOfMoves, ui->spinBox->value());
    //ui->label_2->setText("Необходимо ходов: " + QString::number(amOfMoves));
}

void MainWindow::updateGraphics()
{
    scene->clear();
    sterzhni[0].clear();
    sterzhni[1].clear();
    sterzhni[2].clear();
    ster1 = new QGraphicsRectItem(QRectF(0, 0, 10, 400));
    ster2 = new QGraphicsRectItem(QRectF(350, 0, 10, 400));
    ster3 = new QGraphicsRectItem(QRectF(-350, 0, 10, 400));
    ster1->setBrush(QBrush(Qt::gray));
    ster2->setBrush(QBrush(Qt::gray));
    ster3->setBrush(QBrush(Qt::gray));
    scene->addItem(ster1);
    scene->addItem(ster2);
    scene->addItem(ster3);
   //  aItem = scene->addText("A");
   //  bItem = scene->addText("B");
    // cItem = scene->addText("C");

    //QFont font = aItem->font();
   // font.setPointSize(30);
   // aItem->setFont(font);
   // bItem->setFont(font);
   // cItem->setFont(font);

   // aItem->setPos(-360, 400);
   // bItem->setPos(-10, 400);
   // cItem->setPos(340, 400);

    for (int i = 0; i < ui->spinBox->value(); ++i) {
        sterzhni[0].push(new QGraphicsRectItem(QRectF(-420 + 5 * i, 380 - i * 20, 150 - i * 10, 20)));
        sterzhni[0].top()->setBrush(QBrush(QColor(Qt::yellow)));
        scene->addItem(sterzhni[0].top());
    }
    i = 0;
}


void MainWindow::on_pushButton_clicked()
{
    if (i == ui->tableWidget->rowCount()) {
        ui->pushButton->setDisabled(true);
        return;
    }
    if (animationTimer->isActive()) {
        animationTimer->stop();
        ui->spinBox->setDisabled(false);
        ui->pushButton->setText("начать");
     //   ui->forwardButton->setDisabled(false);
     //   ui->backButton->setDisabled(false);
    }
    else {
        animationTimer->start(500);
        ui->spinBox->setDisabled(true);
        ui->pushButton->setText("остановить");
     //   ui->forwardButton->setDisabled(true);
     //   ui->backButton->setDisabled(true);
    }
}


// void MainWindow::on_backButton_clicked()
// {
//     if (i == ui->tableWidget->rowCount()) {
//         ui->forwardButton->setDisabled(false);
//         ui->pushButton->setDisabled(false);
//     }
//     i--;
//     ui->tableWidget->selectRow(i);
//     move.Moves(sterzhni, ui->tableWidget->item(i, 1)->text().at(0).toLatin1() - 'A',
//                ui->tableWidget->item(i, 0)->text().at(0).toLatin1() - 'A');
//     ui->forwardButton->setDisabled(true);
//     ui->backButton->setDisabled(true);
//     ui->pushButton->setDisabled(true);
//     backTimer->start(500);
// }


// void MainWindow::on_forwardButton_clicked()
// {
//     if (i == 0) {
//         ui->backButton->setDisabled(false);
//     }
//     ui->tableWidget->selectRow(i);
//     move.Moves(sterzhni, ui->tableWidget->item(i, 0)->text().at(0).toLatin1() - 'A',
//                ui->tableWidget->item(i, 1)->text().at(0).toLatin1() - 'A');
//     i++;
//     ui->forwardButton->setDisabled(true);
//     ui->backButton->setDisabled(true);
//     ui->pushButton->setDisabled(true);
//     forwardTimer->start(500);
// }

