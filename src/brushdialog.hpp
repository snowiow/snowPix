#ifndef BRUSHDIALOG_HPP
#define BRUSHDIALOG_HPP

#include <QWidget>
#include <QColorDialog>
#include <memory>

namespace Ui {
    class BrushDialog;
}

class BrushDialog : public QWidget {
    Q_OBJECT

    public:
        explicit BrushDialog(QWidget* parent = nullptr);
        virtual ~BrushDialog();

    private:
        std::unique_ptr<Ui::BrushDialog> _ui;
        QColor _currentColor;

        void _createConnects();
        void _setCurrentColor(QColor color);

    signals:
        void colorChanged(const QColor& color);

    private slots:
        void _onColorPickerClicked();

};
#endif //BRUSHDIALOG_HPP

