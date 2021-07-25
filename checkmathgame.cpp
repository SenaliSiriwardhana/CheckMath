#include "checkmathgame.h"
#include "ui_checkmathgame.h"
#include <QDebug>

CheckMathGame::CheckMathGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckMathGame)
{
    ui->setupUi(this);

    srand(time(NULL));

    RealNo=rand() % 10 + 1;

    qDebug() << "Real Number generated: " <<QString::number(RealNo);
    ui->StartOver->setDisabled(true);
    ui->Messagelabel->setText("");
}

CheckMathGame::~CheckMathGame()
{
    delete ui;
}




void CheckMathGame::on_GuessButton_clicked()
{
    GuessNo = ui->spinBox->value();
        qDebug() << "The Guess Number is: " <<QString::number(GuessNo);

        if(GuessNo==RealNo)
        {
            ui->Messagelabel->setText("Congratulations , Number is  "+QString::number(RealNo));
            ui->GuessButton->setDisabled(true);
            ui->StartOver->setDisabled(false);

        }

        else
        {
            if (RealNo<GuessNo)
            {
            ui->Messagelabel->setText("Number is lower than that. ");
            }
            if (RealNo>GuessNo)
            {
            ui->Messagelabel->setText("Number is higher than that. ");
            }
        }


}

void CheckMathGame::on_StartOver_pressed()
{
    ui->GuessButton->setDisabled(false);
    ui->StartOver->setDisabled(true);
    ui->spinBox->setValue(0);
    RealNo = rand() % 10+1;
    ui->Messagelabel->setText("");

}
void CheckMathGame::on_pushButton_pressed()
{
    hide ();
    QWidget *parent = this->parentWidget();
    parent->show();
}
