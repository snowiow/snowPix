#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "newfiledialog.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
_ui(new Ui::MainWindow) {
    _ui->setupUi(this);
    _createConnects();
    _onBrushButtonClicked();
}
MainWindow::~MainWindow() {

}

void MainWindow::_createConnects() {
    //File Actions
    connect(_ui->actionNewFile, SIGNAL(triggered()), this,
            SLOT(_onNewFileActionClicked()));
    //Draw Tool Buttons
    connect(_ui->brushButton, SIGNAL(clicked()), this,
            SLOT(_onBrushButtonClicked()));
    connect(_ui->eraserButton, SIGNAL(clicked()), this,
            SLOT(_onEraserButtonClicked()));
    connect(_ui->fillButton, SIGNAL(clicked()), this,
            SLOT(_onFillButtonClicked()));
    connect(_ui->colorPickerButton, SIGNAL(clicked()), this,
            SLOT(_onColorPickerButtonClicked()));
    connect(_ui->lineButton, SIGNAL(clicked()), this,
            SLOT(_onLineButtonClicked()));
    connect(_ui->rectButton, SIGNAL(clicked()), this,
            SLOT(_onRectButtonClicked()));
    connect(_ui->circleButton, SIGNAL(clicked()), this,
            SLOT(_onCircleButtonClicked()));
    //Drawtool windows with drawarea
    connect(_ui->brushDialog, SIGNAL(colorChanged(const QColor&)),
            _ui->drawContents, SLOT(setPenColor(const QColor&)));
    connect(_ui->drawContents, SIGNAL(colorChanged(const QColor&)),
            _ui->brushDialog, SLOT(setColorButtonColor(const QColor&)));
}

void MainWindow::_onNewFileActionClicked() {
    NewFileDialogResult result;
    NewFileDialog dlg(result);
    if (dlg.exec() && dlg.result() == QDialog::Accepted) {
        _ui->drawContents->setImage(new QImage(result.size.x(),
                                    result.size.y(), QImage::Format_RGB32), result.chosenColor);
    }
}

void MainWindow::_onBrushButtonClicked() {
    setCursor(QCursor(QPixmap(":pics/brushCursor")));
    _ui->drawContents->setCurrentTool(DrawArea::DrawTool::Brush);
}

void MainWindow::_onEraserButtonClicked() {
    setCursor(QCursor(QPixmap(":pics/eraserCursor")));
    _ui->drawContents->setCurrentTool(DrawArea::DrawTool::Eraser);
}

void MainWindow::_onColorPickerButtonClicked() {
    setCursor(QCursor(QPixmap(":pics/colorPickerCursor")));
    _ui->drawContents->setCurrentTool(DrawArea::DrawTool::ColorPicker);
}

void MainWindow::_onFillButtonClicked() {
    setCursor(QCursor(QPixmap(":pics/fillCursor")));
    _ui->drawContents->setCurrentTool(DrawArea::DrawTool::Fill);
}

void MainWindow::_onLineButtonClicked() {
    setCursor(QCursor(QPixmap(":pics/lineCursor")));
    _ui->drawContents->setCurrentTool(DrawArea::DrawTool::Line);
}

void MainWindow::_onCircleButtonClicked() {
    setCursor(QCursor(QPixmap(":pics/lineCursor")));
    _ui->drawContents->setCurrentTool(DrawArea::DrawTool::Circle);
}

void MainWindow::_onRectButtonClicked() {
    setCursor(QCursor(QPixmap(":pics/lineCursor")));
    _ui->drawContents->setCurrentTool(DrawArea::DrawTool::Rect);
}