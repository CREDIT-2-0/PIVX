// Copyright (c) 2019 The PIVX developers
// Copyright (c) 2019-2020 The TERRACREDIT developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLCREDITWIDGET_H
#define COINCONTROLCREDITWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlCreditWidget;
}

class CoinControlCreditWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlCreditWidget(QWidget *parent = nullptr);
    ~CoinControlCreditWidget();

private:
    Ui::CoinControlCreditWidget *ui;
};

#endif // COINCONTROLCREDITWIDGET_H
