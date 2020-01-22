#include "../Brick/Brick.h"

class App : public Brick::Application 
{
public:
    App()
    {

    }

    ~App()
    {

    }
};


Brick::Application* Brick::createApplication(){
    return new App();
}