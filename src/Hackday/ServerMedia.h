/*
 * InteractiveProvider.h
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#ifndef SRC_HACKDAY_SERVERMEDIA_H_
#define SRC_HACKDAY_SERVERMEDIA_H_


#include <thread>

namespace connection{
	class ConnectionTCP;
}


class ServerMedia {
public:
	ServerMedia(int port);
	virtual ~ServerMedia();


	void init();

	void assignData(uint8_t* data,int length);

	void end();

protected:

private:

	void loop();

	connection::ConnectionTCP *connection;

	std::thread thread;

	bool finish;

	uint8_t* payload;
	int sizeData;

};

#endif /* SRC_HACKDAY_SERVERMEDIA_H_ */
