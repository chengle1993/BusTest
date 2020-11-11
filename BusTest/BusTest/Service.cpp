#include "Service.h"
#include "engine/qpid_engine.h"
#include <iostream>

Service::Service(sdbus::string url):conn(nullptr)
{
	
	conn = new sdbus::Connection();
	//sdbus::Options options;
	//options.SetOption("heartbeat", 60);
	//conn->SetOptions(options);
	if (!conn->Connect(url))
	{
		std::cout << "connection error..." << std::endl;
	}
	this->Init("pingpong", sdbus::DeliverDirect);
	if (!conn->AddHandler(this))
	{
		std::cout << "addHandler error..." << std::endl;
	}
}
Service::~Service()
{
	releaseQPID();
}

void Service::OnMsgs(const sdbus::Message ** msgs, int count)
{
	for (int i = 0; i < count; ++i)
	{
		const sdbus::Message* mess = *(msgs + i);
		handleRequest(mess);
	}
}

void Service::handleRequest(const sdbus::Message* mess)
{
	std::cout << "start handle message." << std::endl;

	sdbus::string str;
	mess->GetString(1, str);
	std::cout << "received message:" << str << std::endl;

	std::cout << "end handle message." << std::endl;
}

void Service::releaseQPID()
{
	if (conn)
	{
		conn->Close();
		delete conn;
		conn = nullptr;
	}
}