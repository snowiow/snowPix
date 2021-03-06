#ifndef DRAWAREA_HPP
#define DRAWAREA_HPP

#include <memory>
#include <QWidget>
#include <QPen>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
    class DrawArea;
}

class DrawArea : public QWidget {
    Q_OBJECT

    public:
        enum class DrawTool {
            Brush,
            Eraser,
            ColorPicker,
            Fill,
            Line,
            Rect,
            Circle
        };

        explicit DrawArea(QWidget* parent = nullptr);
        virtual ~DrawArea();

        //methods
        void setImage(QImage* image, const QColor& color = Qt::white);
        int getZoom() const {
            return _zoom;
        }

    public slots:
        void setZoom(int value);
        void setPenColor(const QColor& color);
        void setCurrentTool(DrawTool tool);

    signals:
        void colorChanged(const QColor& color);

    protected:
        //methods
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void paintEvent(QPaintEvent* event);

    private:
        //member
        unsigned short _zoom {8};
        DrawTool _currentTool = DrawTool::Brush;
        std::unique_ptr<Ui::DrawArea> _ui;
        std::unique_ptr<QImage> _image;
        std::unique_ptr<QPen> _pen;
        std::unique_ptr<QPen> _gutterPen;
        QColor _backgroundColor;

        //methods
        void _setImagePixel(const QPoint& pos);
        void _resize();
        void _drawImageBorder(QPainter& qPainter);
        QRect _pixelRect(int x, int y) const;
        void _fill(int x, int y, const QRgb& initialColor);
};
#endif // DRAWAREA_HPP
