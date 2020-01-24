
#include "Event.h"

namespace Brick
{
    
    class MouseMoved : public Event
    {
    public:
        MouseMoved(float x, float y) : x(x), y(y) 
        {
            type = EventType::MOUSE_MOVED;
            eventCato = EventCato::MOUSE_EVENT | EventCato::INPUT_EVENT;
        }
        inline float getX() const { return x; }
        inline float getY() const { return y; }
        static EventType getStaticType() { return EventType::MOUSE_MOVED; }
        virtual EventType getEventType() const override { return getStaticType();}
    private:
        float x,y;
    };

    class MouseScrolled : public Event 
    {
    public:
        MouseScrolled(float x, float y) : x(x), y(y) 
        {
            type = EventType::MOUSE_SCROLLED;
            eventCato = EventCato::MOUSE_EVENT | EventCato::INPUT_EVENT;
        }
        inline float getX() const { return x; }
        inline float getY() const { return y; }
        static EventType getStaticType() { return EventType::MOUSE_SCROLLED; }
        virtual EventType getEventType() const override { return getStaticType();}
    private:
        float x,y;
    };

    class MouseButton : public Event 
    {
        protected:
            MouseButton(int button) : button(button)
            {
                eventCato = EventCato::MOUSE_EVENT | EventCato::INPUT_EVENT;
            }
        public:
            inline int getButton() const { return button; }
        private:
            int button;
    };

    class MouseButtonPressed : public MouseButton 
    {
    public:
        MouseButtonPressed(int button) : MouseButton(button)
        {
            type = EventType::MOUSE_BUTTON_PRESSED;
        }
        static EventType getStaticType() { return EventType::MOUSE_BUTTON_PRESSED; }
        virtual EventType getEventType() const override { return getStaticType();}
    };

    class MouseButtonReleased : public MouseButton 
    {
    public:
        MouseButtonReleased(int button) : MouseButton(button)
        {
            type = EventType::MOUSE_BUTTON_RELEASED;
        }
        static EventType getStaticType() { return EventType::MOUSE_BUTTON_RELEASED; }
        virtual EventType getEventType() const override { return getStaticType();}
    };
} // namespace Brick
