#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_saveToFileBtn_clicked()
{

}


void MainWindow::on_addSource1Btn_clicked()
{

}


void MainWindow::on_addSource2Btn_clicked()
{

}


void MainWindow::on_resetBtn_clicked()
{

}


void MainWindow::on_sliderX_sliderMoved(int position)
{

}


void MainWindow::on_sliderY_sliderMoved(int position)
{

}


void MainWindow::on_sliderZ_sliderMoved(int position)
{

}


void MainWindow::on_prevBtn_clicked()
{

}


void MainWindow::on_nextBtn_clicked()
{

}


void MainWindow::on_copyBtn_clicked()
{

}


void MainWindow::on_startBtn_clicked()
{

}


void MainWindow::on_stopBtn_clicked()
{

}

