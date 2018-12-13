# EventDispatcher-cpp
> Subscribe/Publish

```cpp
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
```
