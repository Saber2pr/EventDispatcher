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
    EventDispatcher::getInstance()->addEventListener(string("haha1"), listener1);
    EventDispatcher::getInstance()->addEventListener(string("haha2"), listener2);
    EventDispatcher::getInstance()->addEventListener(string("haha3"), listener3);

    EventDispatcher::getInstance()->removeEventListener("haha1");
    //    EventDispatcher::getInstance()->removeEventListener("haha2");
    //    EventDispatcher::getInstance()->removeEventListener("haha3");

    EventDispatcher::getInstance()->dispatchEvent(string("haha1"), "hello");
    EventDispatcher::getInstance()->dispatchEvent(string("haha2"), "hello");
    EventDispatcher::getInstance()->dispatchEvent(string("haha3"));

    return 0;
}

