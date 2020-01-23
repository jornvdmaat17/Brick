#pragma once

#include <GLFW/glfw3.h>
#include "ApplicationWindows.h"

namespace Brick
{
    
    class Application
    {        
    public:
        Application();
        virtual ~Application();
        void run();
    private:
        Window *window;
        bool running = true;
    };

    Application* createApplication();

} // namespace Brick
