#ifndef DARKSILKMARKET_H
#define DARKSILKMARKET_H

#include <QWidget>
#include <QTimer>
#include <QListWidgetItem>

namespace Ui {
    class DarkSilkMarket;
}

class DarkSilkMarket : public QWidget
{
    Q_OBJECT

public:
    explicit DarkSilkMarket(QWidget *parent = 0);
    ~DarkSilkMarket();
    void subscribeToCoreSignals();
    void unsubscribeFromCoreSignals();
    void updateCategories();

public slots:
    void updateCategory(QString category);

private:
    Ui::DarkSilkMarket *ui;
    

private slots:
    void on_tableWidget_itemSelectionChanged();
    void on_categoriesListWidget_currentItemChanged(QListWidgetItem* current, QListWidgetItem* previous);
    void on_buyButton_clicked();
    void on_viewDetailsButton_clicked();
    void on_copyAddressButton_clicked();
};

#endif // DARKSILKMARKET_H
