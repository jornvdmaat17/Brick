
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
    };

    class WindowFocus : public Event {
    public:
        WindowFocus()
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_FOCUS;
        }
    };

    class WindowNoFocus : public Event {
    public:
        WindowNoFocus()
        {
            eventCato = EventCato::APPLICATION_EVENT;
            type = EventType::WINDOW_NO_FOCUS;
        }
    };
    
} // namespace Brick
