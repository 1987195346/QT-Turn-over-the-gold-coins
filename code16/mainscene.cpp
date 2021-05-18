#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QSound>   // 使用此类前，要现在code16.pro第一行加入   多媒体multimedia
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币场景");

    //退出按钮的实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });


    //准备开始按钮的音效
    QSound * startSound = new QSound(":/res/TapButtonSound.wav",this);
//    startSound->setLoops(-1);//设置循环多少次，如果是-1代表无限循环
//    startSound->play();


    //开始按钮
    MyPushButton * startBtn=new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5 ,this->height() * 0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;

    //监听选择关卡返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        //设置返回时当前主场景的位置为 chooseScene场景的位置
        this->setGeometry(chooseScene->geometry());

        chooseScene->hide();//将选择关卡场景隐藏
        this->show();//重新显示主场景
    });


    connect(startBtn,&MyPushButton::clicked,[=](){
        qDebug()<<"点击了开始按钮";

        //播放开始音效资源
        startSound->play();

        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入到选择关卡场景中
        QTimer::singleShot(500,this,[=](){

            //设置chooseScene场景的位置，为当前主场景的位置
            chooseScene->setGeometry(this->geometry());

            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScene->show();

        });


    });




}

//重写paintEvent事件 画背景图
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景图标
    pix.load(":/res/Title.png");
    //缩放
    pix = pix.scaled(pix.width() * 0.5 , pix.height() * 0.5);

    painter.drawPixmap(10,30,pix);
}

MainScene::~MainScene()
{
    delete ui;
}

