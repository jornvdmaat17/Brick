
#include "Event.h"

namespace Brick
{
    
    class KeyEvent : public Event 
    {
    public:
        inline int getKey() const { return key; }
    protected:
        KeyEvent(int key) : key(key) 
        {
            eventCato = EventCato::KEYBOARD_EVENT | EventCato::INPUT_EVENT;
        }
        int key;
    };

    class KeyPressedEvent : public KeyEvent 
    {
    public:
        KeyPressedEvent(int key, int count) : KeyEvent(key), count(count)
        {
            type = EventType::KEY_PRESSED;
        }
        inline int getCount() const { return count; }
        static EventType getStaticType() { return EventType::KEY_PRESSED; }
        virtual EventType getEventType() const override { return getStaticType();}
    private:
        int count;
    };

    class KeyReleasedEvent : public KeyEvent 
    {
    public:
        KeyReleasedEvent(int key) : KeyEvent(key) 
        {
            type = EventType::KEY_RELEASED;
        }
        static EventType getStaticType() { return EventType::KEY_RELEASED; }
        virtual EventType getEventType() const override { return getStaticType();}    
    };

} // namespace Brick
