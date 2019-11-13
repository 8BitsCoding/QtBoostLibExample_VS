#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtBoostLibExample_VS.h"

class QtBoostLibExample_VS : public QWidget
{
	Q_OBJECT

public:
	QtBoostLibExample_VS(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtBoostLibExample_VSClass ui;
};
