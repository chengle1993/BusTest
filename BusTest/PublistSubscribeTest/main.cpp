// PublistSubscribeTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "sdbus/connection.h"
#include "engine/qpid_engine.h"
#include "Subscribe.h"
#include "boost/thread.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

int main()
{
	engine::qpid::EngineInitializer qpidEngine;
	engine::qpid::LogLevel(5);

#if 0
	sdbus::Connection* conn = new sdbus::Connection();
	if (!conn->Connect("172.16.66.62"))
	{
		std::cerr << "connection error..." << std::endl;
	}
	while (true)
	{
		sdbus::Message mess;
		mess.SetString(1, "hello");
		if (!conn->Publish("subscribe_queue_name", mess))//发布
		{
			std::cerr << "publish message error..." << std::endl;
			return -1;
		}
		boost::this_thread::sleep(boost::posix_time::seconds(1));
	}
#else
	Subscribe subscribe("172.16.66.62");//订阅
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::seconds(1));
	}
#endif
	return 0;
}
