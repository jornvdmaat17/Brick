
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
        inline virtual const char* getName() const override { return "WindowClose"; }
    };

    class WindowFocus : public Event {
    public:
        WindowFocus()
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_FOCUS;
        }
        inline virtual const char* getName() const override { return "WindowFocus"; }
    };

    class WindowNoFocus : public Event {
    public:
        WindowNoFocus()
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_NO_FOCUS;
        }
        inline virtual const char* getName() const override { return "WindowNoFocus"; }
    };
    
} // namespace Brick
