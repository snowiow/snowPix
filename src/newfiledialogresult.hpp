#ifndef NEWFILEDIALOGRESULT_HPP
#define NEWFILEDIALOGRESULT_HPP

#include <memory>
#include <QPoint>

class NewFileDialogResult {
    public:
        QPoint size;
        explicit NewFileDialogResult();
        ~NewFileDialogResult();
};

#endif // NEWFILEDIALOGRESULT_HPP
