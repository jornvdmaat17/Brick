#include "Application.h"
#include "events/ApplicationEvent.h"
#include "src/Logger.h"

namespace Brick
{

    Application::Application()
    {
        window = Window::create();
    }

    Application::~Application()
    {
    }

    void Application::run(){
        WindowResize e(1280, 720);
        if(e.hasEventCato(EventCato::APPLICATION_EVENT))
        {
            while(running)
            {
                Logger::logBrickInfo(e.getName());
                glClearColor(1, 0, 0, 1);
                glClear(GL_COLOR_BUFFER_BIT);
                window->onUpdate();
            }
            if(e.hasEventCato(EventCato::INPUT_EVENT))
            {
                Logger::logBrickInfo(e.getName());
            }

            while(true);
        }
    }

} // namespace Brick
