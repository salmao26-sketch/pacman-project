#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QPoint>
#include "pacman.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override; // Handles keyboard input
    void paintEvent(QPaintEvent *event) override;  // Responsible for drawing the game screen

private slots:
    void gameLoop(); // Runs every tick to update game logic

private:
    Pacman *pacman; // Pacman character instance
    QTimer *timer;  // Timer to control game updates
    int score;      // Player score
    QVector<QPoint> pellets; // Vector holding pellet positions
    void initializePellets(); // Setup initial pellet layout

    // Enemy logic
    QPoint enemyPos; // Current position of the enemy
    int enemyDx, enemyDy; // Direction of enemy movement
    void moveEnemy(); // Update enemy position
};

#endif // MAINWINDOW_H
