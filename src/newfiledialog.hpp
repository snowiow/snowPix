#ifndef NEWFILEDIALOG_HPP
#define NEWFILEDIALOG_HPP

#include <QDialog>
#include <QListWidgetItem>
#include <QColorDialog>
#include <string>

#include "newfiledialogresult.hpp"

using std::to_string;

namespace Ui {
    class NewFileDialog;
}

class NewFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFileDialog(NewFileDialogResult& result, QWidget *parent = nullptr);
    ~NewFileDialog();

private:
    std::unique_ptr<Ui::NewFileDialog> _ui;
    NewFileDialogResult& _result;

    void _createConnects();

private slots:
    void _onSizeChanged();
    void _onColorPickerClicked();
};

#endif // NEWFILEDIALOG_HPP
