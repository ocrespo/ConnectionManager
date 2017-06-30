/*
 * EventList.h
 *
 *  Created on: 30 May 2017
 */

#ifndef EVENTMULTIPLE_H_
#define EVENTMULTIPLE_H_

#include <list>
#include <cstdlib>

#include "Event.h"

/**
 * Should be use with a std::function
 */
template<typename T>
class EventMultiple : public Event{
public:

	/**
	 * Default constructor
	 */
	EventMultiple() : eventList(0) {}

	/**
	 * Construct the class initialising the list with the callback
	 * @param key the key of the event
	 * @param callback the event
	 */
	EventMultiple(u32_t key,const T &callback) : eventList(1,std::pair<u32_t,T>(key,callback)) {}

	/**
	 * Default constructor
	 */
	virtual ~EventMultiple() {
		eventList.clear();
	}

	/**
	 *	Add a new callback with the given key
	 * @param key the key of the callbacl
	 * @param callback the callback
	 * @return If success
	 */
	bool_t registerEvent(u32_t key,T callback){
		if(callback == NULL){
			return FALSE;
		}
		eventList.remove_if([&key](std::pair<u32_t,T> value){
			return value.first == key;
		});

		eventList.push_back(std::pair<u32_t,T>(key,callback));

		return TRUE;
	}

	/**
	 *	Remove the callback with the given key
	 * @param key the key of the callback to remove
	 * @return If success
	 */
	bool_t unregisterEvent(u32_t key){
		size_t prev_size(eventList.size());
		eventList.remove_if([&key](std::pair<u32_t,T> value){
			return value.first == key;
		});

		if(prev_size > eventList.size()){
			return TRUE;
		}
		return FALSE;
	}

	/**
	 * Call the callbacks
	 * @param arg the arguments
	 * @return if success
	 */
	template<typename ...args>
	bool_t notify(args... arg){
		if(eventList.empty()){
			return FALSE;
		}
		for(auto it = eventList.begin(); it != eventList.end(); ++it){
			(*it).second(arg...);
		}

		return TRUE;
	}

protected:


private:

	std::list<std::pair<u32_t ,T>> eventList;

};

#endif /* EVENTMULTIPLE_H_ */
