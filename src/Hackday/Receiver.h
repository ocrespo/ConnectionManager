/*
 * Receiver.h
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#ifndef SRC_RECEIVER_H_
#define SRC_RECEIVER_H_

#include <thread>
#include <deque>
#include <functional>

namespace connection{
	class ConnectionUDP;
}

using callback_t =  std::function<void(struct sPackage*)>;

class Receiver {
public:
	Receiver(int port);

	virtual ~Receiver();

	void registerCallback(const callback_t& callback);

	void init();
	void stop();

protected:


private:

	void receiveLoop();

	connection::ConnectionUDP *connection;

	bool finish;

	std::thread thread;


	callback_t newPackage_callback;


};

#endif /* SRC_RECEIVER_H_ */
