# EventDispatcher
> Subscribe/Publish

```cpp
void EventDispatcher::dispatch(string eventName, Message value = "__DEFAULT__"){
    vector<int> Events = this->FindEvent(eventName);
    this->for_eachEvent(Events,[=](int index){
        this->_Listeners[index](value);
    });
}
```
