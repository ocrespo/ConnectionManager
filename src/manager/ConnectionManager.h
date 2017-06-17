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

	virtual ~ConnectionManager();

protected:


private:

	ConnectionManager();

	class ConnectionBase *connection;



	friend class ConnectionBuilder;
};

#endif /* SRC_MANAGER_CONNECTIONMANAGER_H_ */
