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
        static EventType getStaticType() { return EventType::WINDOW_RESIZE; }
        virtual EventType getEventType() const override { return getStaticType();}
        inline virtual const char* getName() const override { return "WindowResize"; }
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
        static EventType getStaticType() { return EventType::WINDOW_CLOSE; }
        virtual EventType getEventType() const override { return getStaticType();}
        inline virtual const char* getName() const override { return "WindowClose"; }
    };

    class WindowFocus : public Event {
    public:
        WindowFocus()
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_FOCUS;
        }
        static EventType getStaticType() { return EventType::WINDOW_FOCUS; }
        virtual EventType getEventType() const override { return getStaticType();}
        inline virtual const char* getName() const override { return "WindowFocus"; }
    };

    class WindowNoFocus : public Event {
    public:
        WindowNoFocus()
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_NO_FOCUS;
        }
        static EventType getStaticType() { return EventType::WINDOW_NO_FOCUS; }
        virtual EventType getEventType() const override { return getStaticType();}
        inline virtual const char* getName() const override { return "WindowNoFocus"; }
    };
    
} // namespace Brick
