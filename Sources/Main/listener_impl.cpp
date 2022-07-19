#include "listener_impl.hpp"


/////////////////////////////////////////////////////
//					Listener1Impl
/////////////////////////////////////////////////////

void Listener1Impl::onSomethingHappened1()
{
	std::cout << "Listener1Impl::onSomethingHappened1\n";
}

void Listener1Impl::onSomethingHappened3(int value)
{
	std::cout << "Listener1Impl::onSomethingHappened3; value = " << value << std::endl;
}


/////////////////////////////////////////////////////
//					Listener2Impl
/////////////////////////////////////////////////////

void Listener2Impl::onSomethingHappened1()
{
	std::cout << "Listener2Impl::onSomethingHappened1\n";
}

void Listener2Impl::onSomethingHappened2()
{
	std::cout << "Listener2Impl::onSomethingHappened2;\n";
}


/////////////////////////////////////////////////////
//				ListenerControllerImpl
/////////////////////////////////////////////////////

void ListenersControllerImpl::doSomething1()
{
	std::cout << "\ndoSomething1 called\n";
	invoke(&IListener::onSomethingHappened1);
}

void ListenersControllerImpl::doSomething2()
{
	std::cout << "\ndoSomething2 called\n";
	invoke(&IListener::onSomethingHappened2);
}

void ListenersControllerImpl::doSomething3()
{
	std::cout << "\ndoSomething3 called\n";
	// send some value to listener
	invoke(&IListener::onSomethingHappened3, 123);
}