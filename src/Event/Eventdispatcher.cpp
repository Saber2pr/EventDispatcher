#include "Eventdispatcher.h"

EventDispatcher::EventDispatcher()
{
}

EventDispatcher::~EventDispatcher()
{
    delete EventDispatcher::_instance;
}

EventDispatcher* EventDispatcher::_instance = nullptr;

EventDispatcher* EventDispatcher::getInstance(){
    if(_instance == nullptr){
        _instance = new EventDispatcher();
    }
    return _instance;
}

void EventDispatcher::addEventListener(string name, Listener listener){
    Event event;
    event.name = name;
    event.listener = listener;
    this->EventList.push_back(event);
}

void EventDispatcher::dispatchEvent(string name, Message value){
    for_each(this->EventList.begin(), this->EventList.end(), [=](Event event){
        event.name == name? event.listener(value): void();
    });
}

void EventDispatcher::removeEventListener(string name){
    vector<Event> event_filtered(this->EventList.size());
    auto end = copy_if(this->EventList.begin(), this->EventList.end(), event_filtered.begin(), [=](Event event_cur){
        return event_cur.name == name? false: true;
    });
    event_filtered.resize(distance(event_filtered.begin(), end));
    this->EventList = event_filtered;
}
