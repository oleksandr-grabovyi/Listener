#pragma once

#include <set>
#include <memory>
#include <iostream>

/////////////////////////////////////////////////////
//					IListener
/////////////////////////////////////////////////////

class IListener
{
public:
	// example of methods that MUST BE implemented
	virtual void onSomethingHappened1() = 0;

	// example of methods that CAN BE implemented for listening something
	virtual void onSomethingHappened2() 
	{
		std::cout << "IListener::onSomethingHappened2\n";
	};

	virtual void onSomethingHappened3(int value)
	{
		std::cout << "IListener::onSomethingHappened3; value = " << value << std::endl;
	}
};


/////////////////////////////////////////////////////
//				ListenersControllerBase
/////////////////////////////////////////////////////

// Base implementation of controller. All listener methods should calls manualy
template<class ListenerType>
class ListenersControllerBase
{
public:
	virtual void registerListener(ListenerType* listener)
	{
		m_listeners.insert(listener);
	};

	virtual void unregisterListener(ListenerType* listener)
	{
		if (m_listeners.find(listener) != m_listeners.end())
		{
			m_listeners.erase(listener);
		}
	};

	using ListenersList = std::set<ListenerType*>;
protected:
	ListenersList m_listeners;
};


/////////////////////////////////////////////////////
//				ListenersControllerWithCallMethod
/////////////////////////////////////////////////////

// Extended implementation of controller which provides invoke method to simplify listeners calling.
template<class ListenerType>
class ListenersControllerWithInvoke : public ListenersControllerBase<ListenerType>
{
public:
	template<class CallbackType, class ... P>
	void invoke(CallbackType cb, P ... params)
	{
		for (auto listener : m_listeners)
		{
			(*listener.*cb)(std::forward<P>(params)...);
		}
	}
};

using ListenersController = ListenersControllerWithInvoke<IListener>;