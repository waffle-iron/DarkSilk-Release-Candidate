#ifndef OVERVIEWPAGE_H
#define OVERVIEWPAGE_H

#include "amount.h"

#include <QWidget>
#include <QTimer>

class ClientModel;
class WalletModel;
class TxViewDelegate;
class TransactionFilterProxy;

namespace Ui {
    class OverviewPage;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = 0);
    ~OverviewPage();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);
    void showOutOfSyncWarning(bool fShow);
    void updateSandstormProgress();

public slots:
    void sandStormStatus();
    void setBalance(const CAmount& balance, const CAmount& stake, const CAmount& unconfirmedBalance, const CAmount& immatureBalance, const CAmount& anonymizedBalance);

signals:
    void transactionClicked(const QModelIndex &index);

private:
    QTimer *timer;
    Ui::OverviewPage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;
    CAmount currentBalance;
    CAmount currentStake;
    CAmount currentUnconfirmedBalance;
    CAmount currentImmatureBalance;
    CAmount currentAnonymizedBalance;
    
    qint64 lastNewBlock;

    int showingSandStormMessage;
    int sandstormActionCheck;
    int cachedNumBlocks;
    int cachedTxLocks;
    TxViewDelegate *txdelegate;
    TransactionFilterProxy *filter;

private slots:
    void toggleSandstorm();
    void sandstormAuto();
    void sandstormReset();
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex &index);
    void updateAlerts(const QString &warnings);
};

#endif // OVERVIEWPAGE_H
