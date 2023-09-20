#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags type)
    : QMainWindow(parent, type)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Тестовые виджеты");
    ui->gb_choose->setTitle("Варианты");

    ui->rb_first->setText("Радио 1");
    ui->rb_second->setText("Радио 2");

    for (int i = 0; i < 7; ++i)
    {
        ui->cb_list->addItem("Элемент " + QString::number(i + 1));
    }

    ui->pb_add->setText("Увеличить прогресс бар");
    ui->pb_add->setCheckable(true);

    ui->prb_sum->setMinimum(0);
    ui->prb_sum->setMaximum(10);
    ui->prb_sum->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_add_clicked()
{
    int tmp = ui->prb_sum->value() + ui->prb_sum->maximum()/10;
    if(tmp > ui->prb_sum->maximum())
    {
        ui->prb_sum->setValue(0);
        //ui->prb_sum->reset();
    }
    else
    {
        ui->prb_sum->setValue(tmp);
    }
}

