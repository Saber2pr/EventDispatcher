#ifndef EVENTDISPATCH_H
#define EVENTDISPATCH_H
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * @brief The EventDispatcher class
 * @infor: by saber2pr
 */
class EventDispatcher
{
private:
    /**
     * @brief _instance
     */
    static EventDispatcher *_instance;
    /**
     * @brief EventDispatcher
     */
    EventDispatcher();
    /**
     * @brief Message
     */
    using Message = string;
    /**
     * @brief Listener
     */
    using Listener = function<void(Message)>;
    /**
     * @brief The Event struct
     */
    struct Event {
        string name;
        Listener listener;
    };
    /**
     * @brief EventList
     */
    vector<Event> EventList;

public:
    /**
     * @brief ~EventDispatcher
     */
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
    void addEventListener(string name ,Listener listener);
    /**
     * @brief removeEvent
     * @param eventName
     */
    void removeEventListener(string name);
    /**
     * @brief dispatch
     * @param eventName
     * @param value
     */
    void dispatchEvent(string name,Message value = "__DEFAULT__");
};

#endif // EVENTDISPATCH_H
