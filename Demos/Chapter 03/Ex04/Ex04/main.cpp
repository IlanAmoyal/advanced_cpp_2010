#include <iostream>
#include "object.h"
#include "string.h"
#include "worker.h"

int main(int argc, char **argv)
{
	Object *pObj = new String("Hello world!");
	std::cout << *pObj << std::endl;
	
	Object *pWorker = new Worker("Ilan Amoyal", "12345678");
	std::cout << *pWorker << std::endl;
	
	delete pObj;
	delete pWorker;
}