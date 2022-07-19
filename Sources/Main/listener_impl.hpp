#pragma once

#include "listener_base.hpp"


/////////////////////////////////////////////////////
//					Listener1Impl
/////////////////////////////////////////////////////

class Listener1Impl : public IListener
{
public:
	virtual void onSomethingHappened1() override;
	virtual void onSomethingHappened3(int value) override;
};


/////////////////////////////////////////////////////
//					Listener2Impl
/////////////////////////////////////////////////////

class Listener2Impl : public IListener
{
public:
	virtual void onSomethingHappened1() override;
	virtual void onSomethingHappened2() override;
};


/////////////////////////////////////////////////////
//				ListenerControllerImpl
/////////////////////////////////////////////////////

class ListenersControllerImpl : public ListenersController
{
public:
	ListenersControllerImpl() = default;

	void doSomething1();
	void doSomething2();
	void doSomething3();
};