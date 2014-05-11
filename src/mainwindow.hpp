#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <memory>
#include <QMainWindow>

#include "newfiledialogresult.hpp"
#include "drawcontents.hpp"
#include "drawarea.hpp"

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
    void _onBrushButtonClicked();

    void _onEraserButtonClicked();

    void _onColorPickerButtonClicked();

    void _onFillButtonClicked();

    void _onLineButtonClicked();

    void _onCircleButtonClicked();

    void _onRectButtonClicked();
};

#endif // MAINWINDOW_HPP
