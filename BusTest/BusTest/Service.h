#pragma once
#include "sdbus/callback.h"
#include "sdbus/connection.h"
//#include <qpid/messaging/Connection.h>
//#include <qpid/messaging/Session.h>
//#include <qpid/messaging/Receiver.h>
//#include <qpid/messaging/Sender.h>
//#include <qpid/messaging/Address.h>
//#include <qpid/messaging/Message.h>

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

