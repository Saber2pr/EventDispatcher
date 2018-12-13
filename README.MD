# EventDispatcher-cpp
> Subscribe/Publish

```cpp
void EventDispatcher::addEventListener(string eventName, Listener listener){
    Event event;
    event.name = eventName;
    event.listener = listener;
    this->EventList.push_back(event);
}

void EventDispatcher::dispatchEvent(string eventName, Message value){
    for_each(this->EventList.begin(), this->EventList.end(), [=](Event event){
        event.name == eventName? event.listener(value): void();
    });
}

void EventDispatcher::removeEventListener(string eventName){
    vector<Event> event_filtered(this->EventList.size());
    auto end = copy_if(this->EventList.begin(), this->EventList.end(), event_filtered.begin(), [=](Event event_cur){
        return event_cur.name == eventName? false: true;
    });
    event_filtered.resize(distance(event_filtered.begin(), end));
    this->EventList = event_filtered;
}
```
