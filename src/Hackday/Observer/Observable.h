/*
 * Observable.h
 *
 *  Created on: 31 May 2017
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <vector>

#include <StdDefines.h>
/**
 * This class should be used with pointers
 */
template<typename K,class T>
class Observable {
public:

	/**
	 * Default destructor
	 */
	virtual ~Observable() {
		for(auto it = observers.begin(); it != observers.end();++it){
			if(*it != NULL){
				delete *it;
			}
		}
	}

protected:

	/**
	 * Create a new Observable with a size of the K::TotalAmount (an enum with this field at the end to set a number of observers) elements
	 */
	Observable() : observers(K::Max,NULL) {
		}

	/**
	 * Create a new Observable with a size of the K::TotalAmount (an enum with this field at the end to set a number of observers) elements
	 * Also add the given observer. Bear in mind you are responsible to give a viable observer due the function won't return any error
	 *
	 * @param key the key to put the observer
	 * @param observer the observer to add
	 */
	Observable(K key,T observer) : observers(K::Max,NULL) {
		addObserver_priv(key,observer);
	}

	/**
	 * Add a new observer T with the given Key K. If there already is an observer with the given key the function do nothing, instead use registerObserver
	 * @param key the key to put the observer
	 * @param observer the observer to add
	 * @return If the observer was added successfully
	 */
	bool_t addObserver(K key, T observer){
		return addObserver_priv(key,observer);
	}

	/**
	 * implementation of addObserver
	 * @param key the key to put the observer
	 * @param observer the observer to add
	 * @return If the observer was added successfully
	 */
	bool_t addObserver_priv(K key, T observer){
		size_t pos (static_cast<int>(key));
		if(pos >= observers.size()){
			return FALSE;
		}
		if(observers[pos] == NULL){
			observers[pos] = observer;
			return TRUE;
		}
		return FALSE;

	}

	/**
	 * Register a new event on the observer with the given key
	 * @param key the key
	 * @param obsKey the observerID
	 * @param event the event to add
	 * @return If was successful
	 */
	template<class Cast,typename Event>
	bool_t registerObserver(K key,u32_t obsKey,const Event& event){
		size_t pos (static_cast<int>(key));
		if(pos >= observers.size() || observers[pos] == NULL){
			return FALSE;
		}
		Cast cast ((Cast)observers[pos]);
		return cast->registerEvent(obsKey,event);
	}

	/**
	 * Remove the observer with the given key
	 * @param key the key of the observer
	 * @return If success
	 */
	bool_t removeObserver(K key){
		size_t pos (static_cast<int>(key));
		if(pos >= observers.size() || observers[pos] == NULL){
			return false;
		}
		T obj(observers[pos]);

		observers[pos] = NULL;

		delete obj;

		return TRUE;
	}

	/**
	 * Unregister the event of the observer with the given Id and the given key
	 * @param key the key
	 * @param obsKey the observerID
	 * @return If success
	 */
	template<class Cast>
	bool_t unregisterObserver(K key,u32_t obsKey){
		size_t pos (static_cast<int>(key));
		if(pos >= observers.size() || observers[pos] == NULL){
			return FALSE;
		}

		return ((Cast)observers[pos])->unregisterEvent(obsKey);

	}

	/**
	 * Do notify
	 * @param key the key of the observer
	 * @param values the values
	 * @return If success
	 */
	template<class Cast,typename ...args>
	bool_t donotify(K key ,args... values){
		size_t pos (static_cast<int>(key));
		if(pos >= observers.size() || observers[pos] == NULL){
			return false;
		}

		Cast cast = reinterpret_cast<Cast>(observers[pos]);
		return cast->template notify<args...>(values...);
	}


	/**
	 * return the observer with the given key
	 * @param key the key
	 * @return the const reference to the observer
	 */
	const T& getObserver(K key){
		return observers[static_cast<int>(key)];
	}


private:

	std::vector<T> observers;

};

#endif /* OBSERVABLE_H_ */
