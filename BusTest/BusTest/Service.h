#pragma once
#include "sdbus/callback.h"
#include "sdbus/connection.h"

class Service : public sdbus::Callback
{
public:
	Service(sdbus::string url);
	~Service();
	void OnMsgs(const sdbus::Message ** msgs, int count);
	void releaseQPID();
	void handleRequest(const sdbus::Message* mess);
private:
	sdbus::Connection* conn;
};

