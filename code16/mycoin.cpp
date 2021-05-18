#include "mycoin.h"
#include <QDebug>
//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{

//}


//参数代表 传入的金币路径 或者银币路径
MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug()<<str;
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器对象
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //监听正面翻反面的信号，并且翻转金币
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        //判断 如果翻完了，将min重置为1
        if(this->min > this->max)
        {
            this->isAnimation=false;//停止做动画
            this->min=1;
            timer1->stop();
        }

    });

    //监听反面翻正面的信号，并且翻转金币
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));

        //判断 如果翻完了，将max重置为8
        if(this->max < this->min)
        {
            this->isAnimation=false;//停止做动画
            this->max=8;
            timer2->stop();
        }

    });

}

//改变标志的方法
void MyCoin::changeFlag()
{
    //如果是正面 翻成反面
    if(this->flag)
    {
        //开始正面翻反面的定时器 30ms
        timer1->start(30);
        isAnimation=true;//开始做动画
        this->flag=false;
    }
    else   //反面翻正面
    {
        //开始反面翻正面的定时器 30ms
        timer2->start(30);
        isAnimation=true;//开始做动画
        this->flag=true;
    }
}

//重写 按下
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    //this->isAnimation防止金币连续切换动画，当this->isAnimation变成false会继续执行    this->isWin是如果胜利了就一直返回，不再响应
    if(this->isAnimation ||this->isWin)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}









