# EventDispatcher
```cpp
void EventDispatcher::dispatch(string eventName, Message value){
    vector<int> Events = this->FindEvent(eventName);
    this->for_eachEvent(Events,[=](int index){
        this->_Listeners[index](value);
    });
}
```
