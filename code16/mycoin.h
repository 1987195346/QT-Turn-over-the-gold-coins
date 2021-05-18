#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);

    //参数代表 传入的金币路径 或者银币路径
    MyCoin(QString btnImg);

    //改变标志的方法
    void changeFlag();

    //重写 按下
    void mousePressEvent(QMouseEvent *);



    QTimer * timer1;//定时器1 正面翻反面定时器
    QTimer * timer2;//定时器2 反面翻正面定时器
    int min = 1;
    int max = 8;

    //执行动画的标志 （防止金币连续翻转时，动画未结束就执行下一次翻转）
    bool isAnimation = false;

    //胜利标志
    bool isWin = false;

    //金币的属性
    int posX;//x坐标位置
    int posY;//y坐标位置
    bool flag;//正反标志


signals:

};

#endif // MYCOIN_H
