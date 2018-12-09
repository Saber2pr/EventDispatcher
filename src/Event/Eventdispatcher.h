#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include<functional>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
/**
 * @brief The EventDispatcher class (Subscribe/Publish)
 * @infor: by saber2pr
 */
class EventDispatcher
{
    typedef string Message;
    typedef function<void(Message)> Listener;

private:
    vector<Listener> _Listeners;
    vector<string> _EventList;
    static EventDispatcher* _instance;

    EventDispatcher();
    /**
     * @brief FindEvent
     * @param eventName
     * @return
     */
    vector<int> FindEvent(string eventName);
    /**
     * @brief for_eachEvent
     * @param Events
     * @param callback
     */
    void for_eachEvent(vector<int> Events,function<void(int)> callback);

public:
    ~EventDispatcher();
    /**
     * @brief getInstance
     * @return
     */
    static EventDispatcher* getInstance();
    /**
     * @brief addEventListener
     * @param eventName
     * @param listener
     */
    void addEventListener(string eventName ,Listener listener);
    /**
     * @brief removeEvent
     * @param eventName
     */
    void removeEvent(string eventName);
    /**
     * @brief dispatch
     * @param eventName
     * @param value
     */
    void dispatch(string eventName,Message value = "__DEFAULT__");
};

#endif // EVENTDISPATCHER_H
