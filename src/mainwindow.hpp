#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <memory>
#include <QMainWindow>

#include "newfiledialogresult.hpp"
#include "drawcontents.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private:
    std::unique_ptr<Ui::MainWindow> _ui;
    void _createConnects();

private slots:
    //File action events
    void _onNewFileActionClicked();

    //Paintbutton events
    void _onBrushButtonClicked() {
        setCursor(QCursor(QPixmap(":pics/brushCursor")));
    }

    void _onEraserButtonClicked() {
        setCursor(QCursor(QPixmap(":pics/eraserCursor")));
    }

    void _onFillButtonClicked() {
        setCursor(QCursor(QPixmap(":pics/fillCursor")));
    }

    void _onLineButtonClicked() {
        setCursor(QCursor(QPixmap(":pics/lineCursor")));
    }

    void _onCircleButtonClicked() {
        setCursor(QCursor(QPixmap(":pics/lineCursor")));
    }

    void _onRectButtonClicked() {
        setCursor(QCursor(QPixmap(":pics/lineCursor")));
    }
};

#endif // MAINWINDOW_HPP
