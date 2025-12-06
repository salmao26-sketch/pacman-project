
#include "pacman.h"
#include <QKeyEvent>

//Constructor to position the pacman in its initial position
Pacman::Pacman(QWidget *parent)
    : QWidget(parent), x(200), y(200), dx(0), dy(0) {}

void Pacman::setDirection(int key) {
    switch (key) {
    case Qt::Key_Up:
        // FILL!! MOVE PACMAN UP
        // HINT!! RELATIVE TO MOVEMENT VECTOR (dx and dy)
        break;
    case Qt::Key_Down:
        // FILL!! MOVE PACMAN DOWN
        // HINT!! RELATIVE TO MOVEMENT VECTOR (dx and dy)
        break;
    case Qt::Key_Left:
        // FILL!! MOVE PACMAN TO THE LEFT
        // HINT!! RELATIVE TO MOVEMENT VECTOR (dx and dy)
        break;
    case Qt::Key_Right:
        // FILL!! MOVE PACMAN TO THE RIGHT
        // HINT!! RELATIVE TO MOVEMENT VECTOR (dx and dy)

        break;
    default:
        break;
    }
}

void Pacman::move() {
    // Update position
    x += dx;
    y += dy;

    // FILLL!! ENSURE THE PACMAN STAYS WITHIN THE WINDOW BOUNDS
    // HINT WE HAVE FOR CASES TO CHECK.
}

void Pacman::draw(QPainter *painter) {

    // EDIT THE BELLOW TO ADD THE PICTURES OF ENEMY RATHER THAN A YELLOW CIRCLE

    painter->setBrush(Qt::yellow); // Pacman's color
    painter->drawEllipse(x, y, 30, 30); // Draw Pacman circle
}

