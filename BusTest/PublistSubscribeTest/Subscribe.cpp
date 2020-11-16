#include "Subscribe.h"
#include "sdbus/connection.h"
#include <iostream>

Subscribe::Subscribe(sdbus::string url):conn(nullptr)
{
	conn = new sdbus::Connection();
	if (!conn->Connect(url))
	{
		std::cerr << "conntion error..." << std::endl;
	}
	this->Init("subscribe_queue_name", sdbus::DeliverPublish);
	if (!conn->AddHandler(this))
	{
		std::cerr << "add handler error..." << std::endl;
	}
}

Subscribe::~Subscribe()
{
	ReleaseQPID();
}

void Subscribe::OnMsgs(const sdbus::Message ** msgs, int count)
{
	for (int i = 0; i < count; ++i)
	{
		const sdbus::Message* mess = *(msgs + i);
		handleMessage(mess);
	}
}

void Subscribe::ReleaseQPID()
{
	if (conn)
	{
		conn->Close();
		conn = nullptr;
		delete conn;
	}
}

void Subscribe::handleMessage(const sdbus::Message* mess)
{
	std::string str;
	mess->GetString(1, str);
	std::cout << "received message:" << str << std::endl;
}