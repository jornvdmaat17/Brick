
#include "Event.h"

namespace Brick
{
    
    class Key : public Event 
    {
    public:
        inline int getKey() const { return key; }
    protected:
        Key(int key) : key(key) 
        {
            eventCato = EventCato::KEYBOARD_EVENT | EventCato::INPUT_EVENT;
        }
        int key;
    };

    class KeyPressed : public Key
    {
    public:
        KeyPressed(int key, int count) : Key(key), count(count)
        {
            type = EventType::KEY_PRESSED;
        }
        inline int getCount() const { return count; }
        static EventType getStaticType() { return EventType::KEY_PRESSED; }
        virtual EventType getEventType() const override { return getStaticType();}
        inline virtual const char* getName() const override { return "KeyPressed"; }
    private:
        int count;
    };

    class KeyReleased : public Key
    {
    public:
        KeyReleased(int key) : Key(key) 
        {
            type = EventType::KEY_RELEASED;
        }
        static EventType getStaticType() { return EventType::KEY_RELEASED; }
        virtual EventType getEventType() const override { return getStaticType();}    
        inline virtual const char* getName() const override { return "KeyRelealed"; }
    };

} // namespace Brick
