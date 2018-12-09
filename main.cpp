#include <iostream>
#include"./src/console/console.hpp"
#include"./src/Event/Eventdispatcher.h"

using namespace std;

void listener1(string value){
    Console::log("listener1: ",value);
}

void listener2(string value){
    Console::log("listener2: ",value);
}

void listener3(string value){
    Console::log("listener3: ",value);
}


int main()
{
    EventDispatcher::getInstance()->addEventListener("haha1", listener1);
    EventDispatcher::getInstance()->addEventListener("haha2", listener2);
    EventDispatcher::getInstance()->addEventListener("haha3", listener3);

    EventDispatcher::getInstance()->removeEvent("haha2");

    EventDispatcher::getInstance()->dispatch("haha1", "hello");
    EventDispatcher::getInstance()->dispatch("haha3");

    return 0;
}

