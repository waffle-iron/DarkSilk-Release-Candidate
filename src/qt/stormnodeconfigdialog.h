#ifndef STORMNODECONFIGDIALOG_H
#define STORMNODECONFIGDIALOG_H

#include <QDialog>

namespace Ui {
    class StormNodeConfigDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class StormNodeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StormNodeConfigDialog(QWidget *parent = 0, QString nodeAddress = "123.456.789.123:31000", QString privkey="STORMNODEPRIVKEY");
    ~StormNodeConfigDialog();

private:
    Ui::StormNodeConfigDialog *ui;
};

#endif // STORMNODECONFIGDIALOG_H
