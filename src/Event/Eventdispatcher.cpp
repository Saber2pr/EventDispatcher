#include "./Eventdispatcher.h"

EventDispatcher::EventDispatcher()
{

}

EventDispatcher::~EventDispatcher()
{
    this->_Listeners.clear();
    delete EventDispatcher::_instance;
}

vector<int> EventDispatcher::FindEvent(string eventName){
    vector<int> indexList;
    int num = this->_EventList.size();
    for(int i = 0; i < num; i++){
        if(eventName == this->_EventList[i]){
            indexList.push_back(i);
        }
    }
    return indexList;
}

void EventDispatcher::for_eachEvent(vector<int> Events, function<void (int)> callback){
    for_each(Events.begin(), Events.end(), callback);
}

EventDispatcher* EventDispatcher::_instance = nullptr;

EventDispatcher* EventDispatcher::getInstance(){
    if(!_instance){
        _instance = new EventDispatcher();
        return _instance;
    }
    return _instance;
}

void EventDispatcher::addEventListener(string eventName, Listener listener){
    this->_EventList.push_back(eventName);
    this->_Listeners.push_back(listener);
}

void EventDispatcher::removeEvent(string eventName){
    vector<int> Events = this->FindEvent(eventName);
    this->for_eachEvent(Events,[=](int index){
        this->_EventList.erase(this->_EventList.begin() + index);
        this->_Listeners.erase(this->_Listeners.begin() + index);
    });
}

void EventDispatcher::dispatch(string eventName, Message value){
    vector<int> Events = this->FindEvent(eventName);
    this->for_eachEvent(Events,[=](int index){
        this->_Listeners[index](value);
    });
}
