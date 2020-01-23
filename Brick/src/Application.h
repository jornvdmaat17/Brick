#pragma once

#include <GLFW/glfw3.h>
#include "ApplicationWindows.h"
#include "events/ApplicationEvent.h"

namespace Brick
{
    
    class Application
    {        
    public:
        Application();
        virtual ~Application();
        void run();
        void onEvent(Event& event);
    private:
        bool onWindowClose(WindowClose& event);

        std::unique_ptr<Window> window;
        bool running = true;
    };

    Application* createApplication();

} // namespace Brick
