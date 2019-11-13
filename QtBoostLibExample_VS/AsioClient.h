#pragma once

#include "boost/asio.hpp"

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

private:
	boost::asio::io_service ioservice;
	std::shared_ptr<boost::asio::io_service::work> work;
	std::thread worker;
};

