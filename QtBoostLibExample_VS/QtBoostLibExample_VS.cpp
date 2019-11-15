#include "QtBoostLibExample_VS.h"

QtBoostLibExample_VS::QtBoostLibExample_VS(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.paramTable->setColumnCount(2);
	ui.paramTable->setHorizontalHeaderLabels(QString("key;value").split(";"));
	ui.paramTable->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.urlEdit->setText("http://127.0.0.1:5000/");

	connect(client, SIGNAL(read_finish(QString)), this, SLOT(on_success));
}

QtBoostLibExample_VS::~QtBoostLibExample_VS()
{
	delete client;
}

void QtBoostLibExample_VS::on_getBtn_clicked()
{
	QString url = ui.urlEdit->text();
	//    client->Get("www.boost.org","/");

		// https://gist.github.com/voodooGQ/4057330
		// �� ����Ʈ���� �Ʒ��� ����ǥ������ �޾ƿ� ����Ѵ�.
		// ����� ����ǥ���� Ȯ�λ���Ʈ�� https://regex101.com
	QRegularExpression re("^(?:([A-Za-z]+):)?(\\/{0,3})([0-9.\\-A-Za-z]+)(?::(\\d+))?(?:\\/([^?#]*))?(?:\\?([^#]*))?(?:#(.*))?$");
	QRegularExpressionMatch match = re.match(url);
	if (match.hasMatch()) {
		auto hostName = match.captured(3);      // match 3�� hostName
		auto urlPath = "/" + match.captured(5);       // match 5�� url

		client->Get(hostName, urlPath);
	}
}

void QtBoostLibExample_VS::on_success(const QString& msg)
{
	ui.responseEdit->setText(msg);
}