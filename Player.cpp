#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    QAudioOutput* mainthemeoutput = new QAudioOutput();
    bulletsound = new QMediaPlayer();
    bulletsound ->setAudioOutput(mainthemeoutput);
    bulletsound->setSource(QUrl("qrc:/Gunshot Sound Effect (mp3cut.net).mp3"));
    mainthemeoutput ->setVolume(50);


    setPixmap(QPixmap(":/images/spaceship.png").scaled(100,100));
}

void Player::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }

    else if (event->key() == Qt::Key_Space){

        Bullet * bullet = new Bullet();
        bullet->setPos(x()+55,y());
        scene()->addItem(bullet);
        bulletsound->play();


    }
}

void Player::spawn(){

    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
