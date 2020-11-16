#pragma once
#include "sdbus/callback.h"
#include "sdbus/message.h"

class Subscribe : public sdbus::Callback
{
public:
	Subscribe(sdbus::string url);
	~Subscribe();
	virtual void OnMsgs(const sdbus::Message ** msgs, int count);
	void ReleaseQPID();
	void handleMessage(const sdbus::Message* mess);
private:
	sdbus::Connection* conn;
};

