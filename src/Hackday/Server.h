/*
 * Server.h
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#ifndef SRC_HACKDAY_SERVER_H_
#define SRC_HACKDAY_SERVER_H_

#include <string>


class Server {
public:
	Server(int sourcePort,int destPort,int destPortConfig,const std::string& destIp,int mediaPort,const std::string& file);
	virtual ~Server();


	void init();
	void start();

protected:


private:

	void readFile();

	void newPackage(struct sPackage* pkt);

	class Receiver *receiver;

	class Sender *sender;

	class ServerMedia *media;

	std::string filename;
};

#endif /* SRC_HACKDAY_SERVER_H_ */
