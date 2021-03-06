#include "Application.h"
#include "Logger.h"
#include "../stdafx.h"

namespace Brick
{
    #define BIND_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        window = std::unique_ptr<Window>(Window::create());
        window->setEventCallBack(BIND_FN(onEvent));
    }

    Application::~Application()
    {
    }

    void Application::run()
    {
        while(running)
        {
            glClearColor(1, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            window->onUpdate();
        }
    }

    void Application::onEvent(Event& event)
    {
        EventDis dispatcher(event);
        dispatcher.dispatch<WindowClose>(BIND_FN(onWindowClose));
        Logger::logBrickInfo(event.getName());
    }

    bool Application::onWindowClose(WindowClose& event)
    {
        running = false;
        return true;
    }


} // namespace Brick
