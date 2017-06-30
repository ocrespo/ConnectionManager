/*
 * EventSingle.h
 *
 *  Created on: 30 May 2017
 */

#ifndef EVENTSINGLE_H_
#define EVENTSINGLE_H_

#include <cstdlib>

#include "Event.h"


/**
 * Should be use with a std::function
 */
template <typename T>
class EventSingle : public Event{

public:
	/**
	 * Default constructor
	 */
	EventSingle(): event(NULL){};

	/**
	 * Create a EventSingle with the given callback
	 * @param callback
	 */
	EventSingle(T callback):event(callback){};

	/**
	 * Default constructor
	 */
	virtual ~EventSingle(){};


	//REGISTER
	/**
	 * Register the callback
	 * @param key unused parameter, added for compatibilities proposes
	 * @param callback the callback
	 * @return If success
	 */
	bool_t registerEvent(u32_t key,const T &callback){
		if(callback == NULL){
			return FALSE;
		}
		event = callback;
		return TRUE;
	}

	/**
	 * Unregister the callback
	 * @param key  unused parameter, added for compatibilities proposes
	 * @return Always TRUE
	 */
	bool_t unregisterEvent(u32_t key){
		event = NULL;
		return TRUE;
	}

	// NOTIFY
	/**
	 * Call the callback
	 * @param arg the arguments to pass
	 * @return  If success
	 */
	template<typename ...args>
	bool_t notify(args... arg){
		if(event == NULL){
			return FALSE;
		}

		event(arg...);
		return TRUE;

	}

protected:


private:

	T event;

};

#endif /* EVENTSINGLE_H_ */
