#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    _ui(new Ui::MainWindow) {

    _ui->setupUi(this);
    _createConnects();
}

MainWindow::~MainWindow() {
    delete _ui;
}

void MainWindow::_createConnects() {

    //Draw Tool Buttons
    connect(_ui->brushButton,SIGNAL(clicked()), this,
            SLOT(_onBrushButtonClicked()));
    connect(_ui->eraserButton,SIGNAL(clicked()), this,
            SLOT(_onEraserButtonClicked()));
    connect(_ui->fillButton,SIGNAL(clicked()), this,
            SLOT(_onFillButtonClicked()));
    connect(_ui->lineButton,SIGNAL(clicked()), this,
            SLOT(_onLineButtonClicked()));
    connect(_ui->rectButton,SIGNAL(clicked()), this,
            SLOT(_onRectButtonClicked()));
    connect(_ui->circleButton,SIGNAL(clicked()), this,
            SLOT(_onCircleButtonClicked()));
}

void MainWindow::_onBrushButtonClicked() {
    QCursor cursor = QCursor(QPixmap(":pics/brushCursor"));
    setCursor(cursor);
}

void MainWindow::_onEraserButtonClicked() {
    QCursor cursor = QCursor(QPixmap(":pics/eraserCursor"));
    setCursor(cursor);
}

void MainWindow::_onFillButtonClicked() {
    QCursor cursor = QCursor(QPixmap(":pics/fillCursor"));
    setCursor(cursor);
}

void MainWindow::_onLineButtonClicked() {
    QCursor cursor = QCursor(QPixmap(":pics/lineCursor"));
    setCursor(cursor);
}

void MainWindow::_onRectButtonClicked() {
    QCursor cursor = QCursor(QPixmap(":pics/lineCursor"));
    setCursor(cursor);
}

void MainWindow::_onCircleButtonClicked() {
    QCursor cursor = QCursor(QPixmap(":pics/lineCursor"));
    setCursor(cursor);
}
