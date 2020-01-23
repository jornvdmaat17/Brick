
#include "../stdafx.h"
#include "events/Event.h"
#include <GLFW/glfw3.h>

namespace Brick
{
    class Window 
    {
    public:
        static Window* create(unsigned int width = 1920, unsigned int height = 1080, const std::string title = "App");
        inline unsigned int getWidth() { return width; }
        inline unsigned int getHeight() { return height; }
        virtual ~Window() {}
        virtual void onUpdate() = 0;
        using EventCallbackFn = std::function<void(Event&)>;
        inline void setEventCallBack(const EventCallbackFn callback){ this->callback = callback; }
        virtual void setVSync(bool enable) = 0;
        virtual bool isVSync() const = 0;
    protected:        
        EventCallbackFn callback;
        std::string title;
        unsigned int width, height;
    };

    class LinuxWindow : public Window {
    public:
        LinuxWindow(unsigned int width, unsigned int height, const std::string title);
        virtual ~LinuxWindow();
        void onUpdate() override;
        void setVSync(bool enable) override;
        bool isVSync() const override;
    private:
        GLFWwindow *window;
        bool vsync;
    };
} // namespace Brick


