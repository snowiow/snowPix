#ifndef NEWFILEDIALOG_HPP
#define NEWFILEDIALOG_HPP

#include <QDialog>

namespace Ui {
class NewFileDialog;
}

class NewFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFileDialog(QWidget *parent = 0);
    ~NewFileDialog();

private:
    Ui::NewFileDialog *ui;
};

#endif // NEWFILEDIALOG_HPP
