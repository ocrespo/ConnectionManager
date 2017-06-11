/*
 * ConnectionManager.h
 *
 *  Created on: 11 Jun 2017
 *      Author: Oscar Crespo
 */

#ifndef SRC_MANAGER_CONNECTIONMANAGER_H_
#define SRC_MANAGER_CONNECTIONMANAGER_H_

class ConnectionManager {
public:
	ConnectionManager();
	virtual ~ConnectionManager();

protected:


private:

	class ConnectionBase *connection;
};

#endif /* SRC_MANAGER_CONNECTIONMANAGER_H_ */
