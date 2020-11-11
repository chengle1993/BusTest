// BusTest.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Service.h"
#include "boost/thread.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "sdbus/sdbus.h"
#include "engine/qpid_engine.h"

void send(sdbus::Connection* conn, sdbus::string content)
{
	sdbus::Message mess;
	mess.SetString(1, content);

	if (!conn->Send("pingpong", mess))
	{
		std::cout << "send message error." << std::endl;
	}
}

int main(int argc, char* argv[])
{
	engine::qpid::EngineInitializer qpid_engine;
	engine::qpid::LogLevel(5);

	Service service("172.16.66.62");//接受并处理消息

	sdbus::Connection* conn = new sdbus::Connection();
	if (!conn->Connect("172.16.66.62"))
	{
		std::cout << "connetion error." << std::endl;
	}
	while (true)
	{
		send(conn, "hello...");//发送消息
		boost::this_thread::sleep(boost::posix_time::seconds(2));
	}

	conn->Close();
	delete conn;
	return 0;
}

