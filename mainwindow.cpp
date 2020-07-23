#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newCalcuation = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::textAlreadyContainsDot(){
   QString input = ui->textEdit->toPlainText();

   if(input.length()==0)
       return true; // don't put a dot at the beginning of the number

   for(int i=0;i<input.length();i++){
       if(input[i] == '.')
           return true;
   }

   return false;
}

void MainWindow:: setCharacterInTextField(char numberToSet){

    if(newCalcuation){
        ui->textEdit->setText("");
        newCalcuation = false;
    }

    QString input = ui->textEdit->toPlainText();
    ui->textEdit->setText(input+numberToSet);
    ui->textEdit->setAlignment(Qt::AlignRight);
}


void MainWindow::arithmeticOperation(){
    switch(this->choice){
        case ADD:
            answer = number +  ui->textEdit->toPlainText().toDouble();
            ui->textEdit->setText(QString::number(answer));
            ui->textEdit->setAlignment(Qt::AlignRight);
            break;
        case SUBSTRACT:
            answer = number -  ui->textEdit->toPlainText().toDouble();
            ui->textEdit->setText(QString::number(answer));
            ui->textEdit->setAlignment(Qt::AlignRight);
            break;
        case MULTIPLY:
            answer = number *  ui->textEdit->toPlainText().toDouble();
            ui->textEdit->setText(QString::number(answer));
            ui->textEdit->setAlignment(Qt::AlignRight);
            break;
        case DIVIDE:
            answer = number /  ui->textEdit->toPlainText().toDouble();
            ui->textEdit->setText(QString::number(answer));
            ui->textEdit->setAlignment(Qt::AlignRight);
            break;
        default:
            break;
    }
}


void MainWindow::on_pushButton_number0_clicked()
{
    setCharacterInTextField('0');
}

void MainWindow::on_pushButton_number1_clicked()
{
   setCharacterInTextField('1');
}

void MainWindow::on_pushButton_number2_clicked()
{
    setCharacterInTextField('2');
}

void MainWindow::on_pushButton_number3_clicked()
{
   setCharacterInTextField('3');
}

void MainWindow::on_pushButton_number4_clicked()
{
    setCharacterInTextField('4');
}

void MainWindow::on_pushButton_number5_clicked()
{
    setCharacterInTextField('5');
}

void MainWindow::on_pushButton_number6_clicked()
{
    setCharacterInTextField('6');
}

void MainWindow::on_pushButton_number7_clicked()
{
    setCharacterInTextField('7');
}

void MainWindow::on_pushButton_number8_clicked()
{
    setCharacterInTextField('8');
}

void MainWindow::on_pushButton_number9_clicked()
{
    setCharacterInTextField('9');
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!textAlreadyContainsDot())
        setCharacterInTextField('.');
}


void MainWindow::on_pushButton_clear_clicked()
{
    ui->textEdit->setText("");
    ui->lastOperation->setText("");
}

void MainWindow::on_pushButton_backspace_clicked()
{
    QString input = ui->textEdit->toPlainText();
    if(input.length()>0)
        input.resize(input.length()-1);
    ui->textEdit->setText(input);
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_pushButton_add_clicked()
{
    number = ui->textEdit->toPlainText().toDouble();
    choice = ADD;
    ui->textEdit->setText("");
    ui->lastOperation->setText(QString::number(number )+ " +");
}

void MainWindow::on_pushButton_sub_clicked()
{
    number = ui->textEdit->toPlainText().toDouble();
    choice = SUBSTRACT;
    ui->textEdit->setText("");
    ui->lastOperation->setText(QString::number(number )+ " -");
}

void MainWindow::on_pushButton_multi_clicked()
{
    number = ui->textEdit->toPlainText().toDouble();
    choice = MULTIPLY;
    ui->textEdit->setText("");
    ui->lastOperation->setText(QString::number(number )+ " *");
}

void MainWindow::on_pushButton_div_clicked()
{
    number = ui->textEdit->toPlainText().toDouble();
    choice = DIVIDE;
    ui->textEdit->setText("");
    ui->lastOperation->setText(QString::number(number )+ " /");
}

void MainWindow::on_pushButton_equals_clicked()
{
    arithmeticOperation();
    ui->lastOperation->setText("");
    newCalcuation = true;
}
