#ifndef CHECKMATHGAME_H
#define CHECKMATHGAME_H

#include <QDialog>

namespace Ui {
class CheckMathGame;
}

class CheckMathGame : public QDialog
{
    Q_OBJECT

public:
    explicit CheckMathGame(QWidget *parent = nullptr);
    ~CheckMathGame();

private slots:  
    void on_GuessButton_clicked();

    void on_StartOver_pressed();

    void on_pushButton_pressed();

private:
    Ui::CheckMathGame *ui;
    int RealNo, GuessNo;



};

#endif // CHECKMATHGAME_H
