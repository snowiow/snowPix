#ifndef NEWFILEDIALOG_HPP
#define NEWFILEDIALOG_HPP

#include <QDialog>
#include <QListWidgetItem>

#include "newfiledialogresult.hpp"

namespace Ui {
    class NewFileDialog;
}

class NewFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFileDialog(NewFileDialogResult& result, QWidget *parent = nullptr);
    ~NewFileDialog();

private slots:
    void _onSizeChanged();

private:
    std::unique_ptr<Ui::NewFileDialog> _ui;
    void _createConnects();
    NewFileDialogResult& _result;
};

#endif // NEWFILEDIALOG_HPP
