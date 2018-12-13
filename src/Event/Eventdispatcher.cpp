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

void EventDispatcher::addEventListener(string eventName, Listener listener){
    Event event;
    event.name = eventName;
    event.listener = listener;
    this->EventList.push_back(event);
}

void EventDispatcher::dispatchEvent(string eventName, Message value){
    for_each(this->EventList.begin(), this->EventList.end(), [=](Event event){
        if(event.name == eventName){
            event.listener(value);
        }
    });
}

void EventDispatcher::removeEventListener(string eventName){
    vector<Event> event_filtered(this->EventList.size());
    auto end = copy_if(this->EventList.begin(), this->EventList.end(), event_filtered.begin(), [=](Event event_cur){
        if(event_cur.name == eventName){
            return false;
        }else {
            return true;
        }
    });
    event_filtered.resize(distance(event_filtered.begin(), end));
    this->EventList = event_filtered;
}
