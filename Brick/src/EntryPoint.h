#include "Application.h"

int main(int argc, char** argv)
{
    auto brickApp = Brick::createApplication();
    brickApp->run();
    delete brickApp;
}