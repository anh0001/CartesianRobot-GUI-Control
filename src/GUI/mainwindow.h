#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QPushButton>
#include <QLineEdit>
#include <QSerialPortInfo>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_5_clicked();

    void readPositionYFromArduino();

    void on_pushButton_6_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_9_clicked();

     void updateSerialPorts();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort arduino;
    QLineEdit *lineEdit;
    int stepsX;
    int stepsY;
    int selectedBaudrate;

    void moveStepper(char axis, char direction);
    void stopSteppers();
    void updateStatusLabel(const QString &text);
    void updateStatusLabelX(const QString &text);
    void updateStatusLabelY(const QString &text);
    void updateStatusLabelZ(const QString &text);

    bool isArduinoConnected;

    QTimer *timer;

};
#endif // MAINWINDOW_H
