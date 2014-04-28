#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "newfiledialog.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
_ui(new Ui::MainWindow) {
    _ui->setupUi(this);
    _createConnects();
}

MainWindow::~MainWindow() {

}

void MainWindow::_createConnects() {
    //File Actions
    connect(_ui->actionNewFile, SIGNAL(triggered()), this,
            SLOT(_onNewFileActionClicked()));
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

void MainWindow::_onNewFileActionClicked() {
    NewFileDialogResult result;
    NewFileDialog dlg(result);
    if (dlg.exec() && dlg.result() == QDialog::Accepted) {
       _ui->drawArea->image.reset(new QImage(result.size.x(),
                                  result.size.y(), QImage::Format_RGB32));
       _ui->drawArea->image->fill(Qt::white);
   }
}
