
#include "ApplicationWindows.h"

namespace Brick
{
    Window* Window::create(unsigned int width, unsigned int height, const std::string title)
	{
		return new LinuxWindow(width, height, title);
	}

    LinuxWindow::LinuxWindow(unsigned int width, unsigned int height, const std::string title)
    {
        this->width = width;
        this->height = height;
        this->title = title;

        if (int s = glfwInit())
		{
			// TODO: glfwTerminate on system shutdown
			BRICK_CORE_ASSERT(s, "Could not intialize GLFW!");
		}

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(window);
        setVSync(true);
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
        (vsync = enable) == true 
        ? glfwSwapInterval(1) 
        : glfwSwapInterval(0);
    }

    bool LinuxWindow::isVSync() const 
    {
        return vsync;
    }
} // namespace Brick


