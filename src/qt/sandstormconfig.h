#ifndef SANDSTORMCONFIG_H
#define SANDSTORMCONFIG_H

#include <QDialog>

namespace Ui {
    class SandstormConfig;
}
class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class SandstormConfig : public QDialog
{
    Q_OBJECT

public:

    SandstormConfig(QWidget *parent = 0);
    ~SandstormConfig();

    void setModel(WalletModel *model);


private:
    Ui::SandstormConfig *ui;
    WalletModel *model;
    void configure(bool enabled, int coins, int rounds);

private slots:

    void clickBasic();
    void clickHigh();
    void clickMax();
};

#endif // SANDSTORMCONFIG_H
