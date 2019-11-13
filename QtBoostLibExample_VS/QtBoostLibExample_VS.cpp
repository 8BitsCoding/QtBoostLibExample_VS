#include "QtBoostLibExample_VS.h"

QtBoostLibExample_VS::QtBoostLibExample_VS(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.paramTable->setColumnCount(2);
	ui.paramTable->setHorizontalHeaderLabels(QString("key;value").split(";"));
	ui.paramTable->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.urlEdit->setText("http://127.0.0.1:5000/");
}
