#include "Engine.h"

// TODO: project open by args
int main(void)
{
    srand(time(NULL));
     
    Engine::getInstance().run();

    return 0;
}