#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_saveToFileBtn_clicked();

    void on_addSource1Btn_clicked();

    void on_addSource2Btn_clicked();

    void on_resetBtn_clicked();

    void on_sliderX_sliderMoved(int position);

    void on_sliderY_sliderMoved(int position);

    void on_sliderZ_sliderMoved(int position);

    void on_prevBtn_clicked();

    void on_nextBtn_clicked();

    void on_copyBtn_clicked();

    void on_startBtn_clicked();

    void on_stopBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
