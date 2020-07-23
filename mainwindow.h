#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>

#define ADD 1
#define SUBSTRACT 2
#define MULTIPLY 3
#define DIVIDE 4



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    bool newCalcuation;
    int choice;
    double number;
    double answer;

    void setCharacterInTextField(char numberToSet);
    bool textAlreadyContainsDot();
    void arithmeticOperation();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_number0_clicked();
    void on_pushButton_number1_clicked();
    void on_pushButton_number2_clicked();
    void on_pushButton_number3_clicked();
    void on_pushButton_number4_clicked();
    void on_pushButton_number5_clicked();
    void on_pushButton_number6_clicked();
    void on_pushButton_number7_clicked();
    void on_pushButton_number8_clicked();
    void on_pushButton_number9_clicked();

    void on_pushButton_clear_clicked();
    void on_pushButton_backspace_clicked();
    void on_pushButton_dot_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_sub_clicked();
    void on_pushButton_multi_clicked();
    void on_pushButton_div_clicked();
    void on_pushButton_equals_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
