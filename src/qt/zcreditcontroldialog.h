// Copyright (c) 2017-2019 The PIVX developers
// Copyright (c) 2019-2020 The TERRACREDIT developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZCREDITCONTROLDIALOG_H
#define ZCREDITCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zcredit/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZCreditControlDialog;
}

class CZCreditControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZCreditControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZCreditControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZCreditControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZCreditControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZCreditControlDialog(QWidget *parent);
    ~ZCreditControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZCreditControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZCreditControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZCREDITCONTROLDIALOG_H
