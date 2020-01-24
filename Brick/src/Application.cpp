#include "Application.h"
<<<<<<< HEAD
=======
#include "Logger.h"
#include "../stdafx.h"
>>>>>>> 025627b... event dispathcer done

namespace Brick
{
    #define BIND_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
<<<<<<< HEAD
=======
        window = std::unique_ptr<Window>(Window::create());
        window->setEventCallBack(BIND_FN(onEvent));
>>>>>>> 025627b... event dispathcer done
    }

    Application::~Application()
    {
    }

<<<<<<< HEAD
    void Application::run(){
        while(true);
=======
    void Application::run()
    {
        while(running)
        {
            glClearColor(1, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            window->onUpdate();
        }
>>>>>>> 025627b... event dispathcer done
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
