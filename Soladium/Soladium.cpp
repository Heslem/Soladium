#include "Engine.h"

// TODO: project open by args
int main(void)
{
    srand((unsigned int)time((time_t*)NULL));

    Engine::getInstance().run();

    return 0;
}