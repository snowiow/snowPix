#ifndef NEWFILEDIALOGRESULT_HPP
#define NEWFILEDIALOGRESULT_HPP

#include <memory>
#include <QPoint>
#include <QColor>

class NewFileDialogResult {
    public:
        QPoint size;
        QColor chosenColor;
        explicit NewFileDialogResult();
        ~NewFileDialogResult();
};

#endif // NEWFILEDIALOGRESULT_HPP
