#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *_ui;
    void _createConnects();

private slots:
    //File action events
    void _onNewFileActionClicked();

    //Paintbutton events
    void _onBrushButtonClicked();
    void _onEraserButtonClicked();
    void _onFillButtonClicked();
    void _onLineButtonClicked();
    void _onCircleButtonClicked();
    void _onRectButtonClicked();
};

#endif // MAINWINDOW_H
