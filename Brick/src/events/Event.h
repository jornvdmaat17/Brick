
#include "../../stdafx.h"

#define BIT(x) (1 << x)

namespace Brick {

    enum EventType 
    {
        NONE = 0,
        WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_NO_FOCUS, WINDOW_MOVED,
        KEY_PRESSED, KEY_RELEASED,
        MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_MOVED, MOUSE_SCROLLED
    };

    enum EventCato 
    {
        NONE = 0,
        APPLICATION_EVENT = BIT(0),
        INPUT_EVENT = BIT(1),
        KEYBOARD_EVENT = BIT(2),
        MOUSE_EVENT = BIT(3),
        MOUSE_BUTTON  = BIT(4)
    };

    class Event
    {
    private:
        friend class EventDis;
    public:
        virtual EventType getEventType() const { return type; }
        virtual const char* getName() const = 0;
        virtual int getEventCatos() const { return eventCato; }
        virtual std::string ToString() const { return getName(); }

        inline bool hasEventCato(EventCato eventCato)
        {
            return getEventCatos() & eventCato;
        }
    protected:
        EventType type;
        int eventCato;
        bool handled = false;
    };
    
    class EventDis
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDis(Event &event) : event(event) {}

        template<typename T>
        bool dispatch(EventFn<T> func)
        {
            if(event.getEventType() == T::getStaticType())
            {
                event.handled = func(*(T*)&event);
                return true;
            }
            return false;
        }
    private:
        Event &event;
    };    

}
