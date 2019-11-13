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
	worker.join();		// thread의 종료를 기다린다.
	work.reset();		// shared_ptr 메모리 해제
}
