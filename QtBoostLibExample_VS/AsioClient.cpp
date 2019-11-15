#include "AsioClient.h"
#include "qdebug.h"


AsioClient::AsioClient() :
	work(new boost::asio::io_service::work(ioservice)),
	resolver(ioservice)
{
	worker = std::thread([&]() {
		ioservice.run();
	});
}


AsioClient::~AsioClient()
{
	ioservice.stop();
	worker.join();		// thread의 종료를 기다린다.
	work.reset();		// shared_ptr 메모리 해제
}

void AsioClient::Get(const QString& url, const QString& p)
{
	// 1. url -> ep resolve
	server = url.toStdString();
	path = p.toStdString();

	boost::asio::ip::tcp::resolver::query query(server, "http");
	resolver.async_resolve(query, boost::bind(&AsioClient::handle_resolve,
		this, boost::asio::placeholders::error,
		boost::asio::placeholders::iterator));

	// 2. connect

	// 3. send

	// 4. recv
}


void AsioClient::handle_resolve(const boost::system::error_code& err, boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
{
	if (!err) {
		boost::asio::ip::tcp::endpoint ep = *endpoint_iterator;
		qDebug() << ep.address().to_string().c_str();
	}
}
