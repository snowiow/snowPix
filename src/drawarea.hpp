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

class DrawArea : public QWidget
{
    Q_OBJECT

    public:

         //ctor and dtor
        explicit DrawArea(QWidget* parent = nullptr);
        virtual ~DrawArea();

        //methods
        void setImage(QImage* image, QColor color = Qt::white);
        int getZoom() const {
            return _zoom;
        }

    public slots:
        void setZoom(int value);

    protected:
        //methods
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void paintEvent(QPaintEvent* event);

    private:
        //member
        unsigned short _zoom {8};
        std::unique_ptr<Ui::DrawArea> _ui;
        std::unique_ptr<QImage> _image;
        std::unique_ptr<QPen> _pen;

        //methods
        void _setImagePixel(const QPoint& pos, bool opaque);
        void _resize();
        void _drawImageBorder(QPainter& qPainter);
        QRect _pixelRect(int i, int j) const;
};
#endif // DRAWAREA_HPP
