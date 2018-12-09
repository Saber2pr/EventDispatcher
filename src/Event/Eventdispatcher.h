#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include<functional>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

class EventDispatcher
{
    typedef string Message;
    typedef function<void(Message)> Listener;

private:
    vector<Listener> _Listeners;
    vector<string> _EventList;
    static EventDispatcher* _instance;

    EventDispatcher();

    vector<int> FindEvent(string eventName);

    void for_eachEvent(vector<int> Events,function<void(int)> callback);

public:
    ~EventDispatcher();

    static EventDispatcher* getInstance();

    void addEventListener(string eventName ,Listener listener);

    void removeEvent(string eventName);

    void dispatch(string eventName,Message value = "__DEFAULT__");
};

#endif // EVENTDISPATCHER_H
