#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
   // explicit PlayScene(QWidget *parent = nullptr);

    PlayScene(int levelNum);

    //重写paintEvent事件
    void paintEvent(QPaintEvent *);

    int levelIndex;//内部成员属性 记录所选关卡

    //二维数组 存放每个关卡的具体数据
    int gameArray[4][4];

    //金币的二维数组 存放每个金币
    MyCoin * coinBtn[4][4];

    //判断是否胜利的标志
    bool isWin;

signals:
    //不属于一个类的信号名称可以重复
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
