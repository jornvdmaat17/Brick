#pragma once

<<<<<<< HEAD
=======
#include <GLFW/glfw3.h>
#include "ApplicationWindows.h"
#include "events/ApplicationEvent.h"

>>>>>>> 025627b... event dispathcer done
namespace Brick
{
    
    class Application
    {        
    public:
        Application();
        virtual ~Application();

        void run();
<<<<<<< HEAD
=======
        void onEvent(Event& event);
    private:
        bool onWindowClose(WindowClose& event);

        std::unique_ptr<Window> window;
        bool running = true;
>>>>>>> 025627b... event dispathcer done
    };

    Application* createApplication();

} // namespace Brick
