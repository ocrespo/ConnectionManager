/*
 * PackageType.h
 *
 *  Created on: 30 Jun 2017
 *      Author: ocrespo
 */

#ifndef SRC_HACKDAY_PACKAGETYPE_H_
#define SRC_HACKDAY_PACKAGETYPE_H_

#include <string>

const int MTU = 1400;

struct sPackage{

	uint8_t payload[MTU];
	int size;

	sPackage() :
		payload({0}),
		size{0}
	{

	}
};



#endif /* SRC_HACKDAY_PACKAGETYPE_H_ */
