#pragma once

namespace Brick
{
    
    class Application
    {        
    public:
        Application();
        virtual ~Application();

        void run();
    };

    Application* createApplication();

} // namespace Brick
