#pragma once

#include "boost/asio.hpp"
#include "boost/bind.hpp"

#include <QObject>
#include <qstring.h>
#include <memory>
#include <thread>

class AsioClient
{
public:
	AsioClient();
	~AsioClient();

	void Get(const QString& url, const QString& path);
	void handle_resolve(const boost::system::error_code& err,
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator);


private:
	boost::asio::io_service ioservice;
	std::shared_ptr<boost::asio::io_service::work> work;
	std::thread worker;

	std::string server, path;
	boost::asio::ip::tcp::resolver resolver;
};

