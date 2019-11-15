#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtBoostLibExample_VS.h"
#include "AsioClient.h"

class QtBoostLibExample_VS : public QWidget
{
	Q_OBJECT

public:
	QtBoostLibExample_VS(QWidget *parent = Q_NULLPTR);
	~QtBoostLibExample_VS();

private slots:
	void on_getBtn_clicked();
	void on_success(const QString& msg);

private:
	Ui::QtBoostLibExample_VSClass ui;
	AsioClient * client;
};
