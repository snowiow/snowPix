#ifndef NEWFILEDIALOG_HPP
#define NEWFILEDIALOG_HPP

#include <QDialog>
#include <QListWidgetItem>
#include <QColorDialog>
#include <string>
#include <vector>

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
    virtual ~NewFileDialog();

private:
    std::unique_ptr<Ui::NewFileDialog> _ui;
    NewFileDialogResult& _result;
    bool _elementsHidden {false};
    void _createConnects();
    void _hideElements();
    void _showElements();

private slots:
    void _onSizeChanged();
    void _onColorPickerClicked();
    void _onWidthSpinBoxClicked(int value);
    void _onHeightSpinBoxClicked(int value);
};

#endif // NEWFILEDIALOG_HPP
