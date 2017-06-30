/*
 * IObserverId.h
 *
 *  Created on: 2 Jun 2017
 *      Author: ocrespo
 */

#ifndef SRC_COMPONENTLIBRARY_OBSERVERPATTERN_IOBSERVERID_H_
#define SRC_COMPONENTLIBRARY_OBSERVERPATTERN_IOBSERVERID_H_

class IObserverId {

public:
	virtual ~IObserverId() {
		}

	/**
	 * get the Id of this ibserver
	 * @return the ID
	 */
	inline unsigned int getObsrId(){
		return id;
	}

protected:

	/**
	 * Increment the ID by 1 per object
	 */
	IObserverId() {
		static unsigned int count = 0;
		id = count;
		++count;
	}



private:

	unsigned int id;


};

#endif /* SRC_COMPONENTLIBRARY_OBSERVERPATTERN_IOBSERVERID_H_ */
