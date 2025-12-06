#ifndef PACMAN_H
#define PACMAN_H

#include <QWidget>
#include <QPainter>

class Pacman : public QWidget {
    Q_OBJECT

public:
    explicit Pacman(QWidget *parent = nullptr);
    void move(); // Update Pacman's position
    void draw(QPainter *painter); // Draw Pacman
    void setDirection(int key); // Change movement direction

    // FILL THE BELLOW SETTER AND GETTER TO RETURN THE X AND Y POSITION
    int getX() { //FILL }
        int getY() { //FILL }

        private:
            int x, y;   // Pacman's position
            int dx, dy; // Movement vector
        };

#endif // PACMAN_H
