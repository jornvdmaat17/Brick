
#include "../stdafx.h"
#include "events/Event.h"
#include "events/ApplicationEvent.h"
#include "events/Mouse.h"
#include "events/KeyEvent.h"
#include <GLFW/glfw3.h>

namespace Brick
{
    class Window 
    {
    public:
        static Window* create(unsigned int width = 1920, unsigned int height = 1080, const std::string title = "App");
        virtual unsigned int getWidth() const = 0;
        virtual unsigned int getHeight() const = 0;
        virtual ~Window() {}
        virtual void onUpdate() = 0;
        using EventCallbackFn = std::function<void(Event&)>;
        virtual void setEventCallBack(const EventCallbackFn callback) = 0;
        virtual void setVSync(bool enable) = 0;
        virtual bool isVSync() const = 0;       
    };

    class LinuxWindow : public Window {
    public:
        LinuxWindow(unsigned int width, unsigned int height, const std::string title);
        virtual ~LinuxWindow();
        inline unsigned int getWidth() const override { return windowData.width; }
        inline unsigned int getHeight() const override { return windowData.height; }
        inline void setEventCallBack(const EventCallbackFn callback) { windowData.callback = callback; }
        void onUpdate() override;
        void setVSync(bool enable) override;
        bool isVSync() const override;
    private:
        GLFWwindow *window;
        
        struct WindowData {
            EventCallbackFn callback;
            std::string title;
            unsigned int width, height;
            bool vsync;
        };

        WindowData windowData;
    };
} // namespace Brick


