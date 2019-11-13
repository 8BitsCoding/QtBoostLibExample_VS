#include "AsioClient.h"



AsioClient::AsioClient() :
	work(new boost::asio::io_service::work(ioservice))
{
	worker = std::thread([&]() {
		ioservice.run();
	});
}


AsioClient::~AsioClient()
{
	ioservice.stop();
	worker.join();		// thread�� ���Ḧ ��ٸ���.
	work.reset();		// shared_ptr �޸� ����
}
