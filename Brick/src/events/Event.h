<<<<<<< HEAD

#include <string>
=======
#pragma once
#include "../../stdafx.h"
>>>>>>> 025627b... event dispathcer done

#define BIT(x) (1 << x)

namespace Brick {

    enum EventType 
    {
        NO_EVENT = 0,
        WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_NO_FOCUS, WINDOW_MOVED,
        KEY_PRESSED, KEY_RELEASED,
        MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_MOVED, MOUSE_SCROLLED
    };

    enum EventCato 
    {
        NO_EVENT_CATO = 0,
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
        virtual EventType getEventType() const = 0;
        virtual const char* getName() const = 0;
        virtual int getEventCatos() const = 0;
        virtual std::string ToString() const { return getName(); }

        inline bool hasEventCato(EventCato eventCato)
        {
            return getEventCatos() & eventCato;
        }
    protected:
        EventType type;
        int EventCato;
        bool handled = false;
    };
    
    class EventDis
    {
    private:
        
    public:

    };    

}
