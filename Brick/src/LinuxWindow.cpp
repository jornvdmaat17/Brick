
#include "ApplicationWindows.h"

namespace Brick
{
    Window* Window::create(unsigned int width, unsigned int height, const std::string title)
	{
		return new LinuxWindow(width, height, title);
	}

    LinuxWindow::LinuxWindow(unsigned int width, unsigned int height, const std::string title)
    {
        windowData.width = width;
        windowData.height = height;
        windowData.title = title;

        if (int s = glfwInit())
		{
			// TODO: glfwTerminate on system shutdown
            glfwSetErrorCallback([](int code, const char* msg)
            {
                BRICK_CORE_ASSERT("GLFW Error ({0}) : {1}", code, msg);    
            });
			BRICK_CORE_ASSERT(s, "Could not intialize GLFW!");
		}

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, &windowData);
        setVSync(true);

        // GLFW Callbacks
        glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int w, int h)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.width = w;
            data.height = h;
            WindowResize event(w, h);
            data.callback(event);
        });

        glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowClose event;
            data.callback(event);
        });

        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch(action)
            {
                case GLFW_PRESS:
                {
                    KeyPressed event(key, 0);
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleased event(key);
                    data.callback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressed event(key, 1);
                    data.callback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch(action){
                case GLFW_PRESS:
                {
                    MouseButtonPressed event(button);
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleased event(button);
                    data.callback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(window, [](GLFWwindow* window, double xo, double yo){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolled event((float)xo, (float)yo);
            data.callback(event);
        });

        glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMoved event((float)x, (float)y);
            data.callback(event);
        });
    }

    LinuxWindow::~LinuxWindow()
    {
        glfwDestroyWindow(window);
    }
        
    void LinuxWindow::onUpdate() 
    {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    void LinuxWindow::setVSync(bool enable) 
    {
        (windowData.vsync = enable) == true 
        ? glfwSwapInterval(1) 
        : glfwSwapInterval(0);
    }

    bool LinuxWindow::isVSync() const 
    {
        return windowData.vsync;
    }
} // namespace Brick


