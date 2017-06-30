/*
 * Sernder.h
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#ifndef SRC_HACKDAY_SENDER_H_
#define SRC_HACKDAY_SENDER_H_

#include <deque>
#include <thread>
#include <string>
#include <mutex>

namespace connection{
	class ConnectionUDP;
}
struct sPackage;

class Sender {
public:
	Sender(std::string ip,int port,int portConfig,int mediaPort);

	virtual ~Sender();

	void init();
	void end();

	void newPackage(sPackage* package);

protected:


private:

	void sendLoop();
	void sendLoopConfig();

	std::deque<sPackage*> buffer;

	connection::ConnectionUDP *connection;

	connection::ConnectionUDP *connectionInfo;

	std::string destIp;
	int destPort;
	int destPortConfig;
	int sendMediaPort;

	std::thread thread;
	std::thread threadConfig;

	std::mutex mutex;


	bool finish;

};

#endif /* SRC_HACKDAY_SENDER_H_ */
