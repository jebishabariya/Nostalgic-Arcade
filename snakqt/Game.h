#ifndef GAME_H
#define GAME_H
#include<QGraphicsView>
#include<QGraphicsScene>
class Game : public QGraphicsView{
public:
    //constructor
    Game(QWidget* parent =NULL) ;
    void start();
    QGraphicsScene* scene;
    // HrxBoard* hexboard; TODO
    QString whichGame;
};

#endif // GAME_H
