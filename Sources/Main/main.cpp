#include <iostream>
#include "listener_impl.hpp"

int main(int argc, char* argv[])
{
	ListenersControllerImpl controller;
	Listener1Impl listener1;
	Listener2Impl listener2;
	
	std::cout << "register listener1\n";
	controller.registerListener(&listener1);
	std::cout << "register listener2\n";
	controller.registerListener(&listener2);

	controller.doSomething1();
	controller.doSomething2();
	controller.doSomething3();

	std::cout << "\nunregister listener2\n";
	controller.unregisterListener(&listener2);

	controller.doSomething1();
	controller.doSomething2();
	controller.doSomething3();

	return 0;
}