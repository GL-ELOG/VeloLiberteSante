#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_stationBtnAj_clicked();
    void on_stationBtnMod_clicked();
    void on_stationBtnSup_clicked();
    void on_borneBtnAj_clicked();
    void on_borneBtnMod_clicked();
    void on_borneBtnSup_clicked();
    void on_veloBtnAj_clicked();
    void on_veloBtnMod_clicked();
    void on_veloBtnSup_clicked();
    void on_veloBtnCon_clicked();
    void on_abonneBtnAj_clicked();
    void on_abonneBtnMod_clicked();
    void on_abonneBtnSup_clicked();
    void on_abonneBtnCon_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
