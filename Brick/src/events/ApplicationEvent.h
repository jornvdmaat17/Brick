#pragma once
#include "Event.h"

namespace Brick
{
    class WindowResize : public Event {
    public:
        WindowResize(unsigned int width, unsigned int height) : width(width), height(height) 
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_RESIZE;
        }   
        inline unsigned int getWidth(){ return width; }
        inline unsigned int getHeight(){ return height; }
<<<<<<< HEAD
=======
        static EventType getStaticType() { return EventType::WINDOW_RESIZE; }
        virtual EventType getEventType() const override { return getStaticType();}
        inline virtual const char* getName() const override { return "WindowResize"; }
>>>>>>> 025627b... event dispathcer done
    private:
        unsigned int width, height;
    };

    class WindowClose : public Event {
    public:
        WindowClose()
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_CLOSE;
        }
<<<<<<< HEAD
=======
        static EventType getStaticType() { return EventType::WINDOW_CLOSE; }
        virtual EventType getEventType() const override { return getStaticType();}
        inline virtual const char* getName() const override { return "WindowClose"; }
>>>>>>> 025627b... event dispathcer done
    };

    class WindowFocus : public Event {
    public:
        WindowFocus()
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_FOCUS;
        }
<<<<<<< HEAD
=======
        static EventType getStaticType() { return EventType::WINDOW_FOCUS; }
        virtual EventType getEventType() const override { return getStaticType();}
        inline virtual const char* getName() const override { return "WindowFocus"; }
>>>>>>> 025627b... event dispathcer done
    };

    class WindowNoFocus : public Event {
    public:
        WindowNoFocus()
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_NO_FOCUS;
        }
<<<<<<< HEAD
=======
        static EventType getStaticType() { return EventType::WINDOW_NO_FOCUS; }
        virtual EventType getEventType() const override { return getStaticType();}
        inline virtual const char* getName() const override { return "WindowNoFocus"; }
>>>>>>> 025627b... event dispathcer done
    };
    
} // namespace Brick
