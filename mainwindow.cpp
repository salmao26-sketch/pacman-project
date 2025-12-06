#include "mainwindow.h"
#include <QKeyEvent>
#include <QPainter>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pacman(new Pacman(this)), timer(new QTimer(this)), score(0), enemyPos(100, 100), enemyDx(10), enemyDy(0) {
    setFixedSize(400, 400); // Set the window size
    initializePellets(); // Create pellets
    connect(timer, &QTimer::timeout, this, &MainWindow::gameLoop); // Connect timer to game loop
    timer->start(100); // Game updates every 100ms
}

MainWindow::~MainWindow() {}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    pacman->setDirection(event->key()); // Change pacman's direction on key press
}

void MainWindow::initializePellets() {
    // Place pellets in a grid with spacing
    // FILL OUT THE CONDITION OF THE FOR LOOP TO ADD PELLET IN A MAZE FORM
    for (              ) {
        for (                 ) {
            pellets.append(QPoint(x, y));
        }
    }
}

void MainWindow::moveEnemy() {
    // Move enemy by its velocity
    enemyPos.rx() += enemyDx;
    enemyPos.ry() += enemyDy;

    // FILL!! BOUNCE THE ENEMY OFF THE WALLS
    // WE HAVE TWO FOUR CASES TO CHECK

    // FIRST TWO FOR enemyPos.x()
    // SECOND TWO FOR enemyPos.y()


}

void MainWindow::gameLoop() {
    pacman->move(); // Update Pacman's position
    moveEnemy();    // Move the enemy

    QRect pacmanRect(pacman->getX(), pacman->getY(), 30, 30); // Bounding box for collision

    // Check collision with pellets
    for (int i = 0; i < pellets.size(); ++i) {
        QRect pelletRect(pellets[i].x(), pellets[i].y(), 10, 10);
        if (pacmanRect.intersects(pelletRect)) {
            pellets.remove(i); // Remove pellet on collision


            //FILL INCREMENT THE SCORE WHEN PACMAN PASSES ON THE PELLET


            break;
        }
    }

    QRect enemyRect(enemyPos.x(), enemyPos.y(), 30, 30);
    if (pacmanRect.intersects(enemyRect)) {
        timer->stop(); // Stop game on collision with enemy
        // Game over logic here
    }

    update(); // Redraw the window
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    pacman->draw(&painter); // Draw Pacman

    // EDIT THE BELLOW TO ADD THE PICTURES OF PELLET RATHER THAN A BLUE ECLIPSE
    painter.setBrush(Qt::blue);
    for (const QPoint &p : pellets) {
        painter.drawEllipse(p, 5, 5);
    }

    // EDIT THE BELLOW TO ADD THE PICTURES OF ENEMY RATHER THAN A RED ECLIPSE
    painter.setBrush(Qt::red);
    painter.drawEllipse(enemyPos, 15, 15);

    // Draw score
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 14));
    painter.drawText(10, 20, QString("Score: %1").arg(score));
}

