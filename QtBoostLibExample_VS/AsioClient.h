#pragma once

#include "boost/asio.hpp"
#include "boost/bind.hpp"

#include <QObject>
#include <qstring.h>
#include <memory>
#include <thread>

class AsioClient : public QObject
{
	Q_OBJECT
public:
	AsioClient();
	~AsioClient();

	void Get(const QString& url, const QString& path);
	void handle_resolve(const boost::system::error_code& err,
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator);
	void handle_connect(const boost::system::error_code& err,
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator);
	void handle_write(const boost::system::error_code& err);
	void handle_read_line(const boost::system::error_code& err);
	void handle_read_header(const boost::system::error_code& err);
	void handle_read_content(const boost::system::error_code& err);


private:
	boost::asio::io_service ioservice;
	std::shared_ptr<boost::asio::io_service::work> work;
	std::thread worker;

	std::string server, path;
	boost::asio::ip::tcp::resolver resolver;

	boost::asio::ip::tcp::socket socket;

	boost::asio::streambuf requestbuf;
	boost::asio::streambuf responsebuf;

	std::ostringstream oss;

signals:
	void read_finish(const QString& msg);
	void read_failed(const QString& msg);
};

