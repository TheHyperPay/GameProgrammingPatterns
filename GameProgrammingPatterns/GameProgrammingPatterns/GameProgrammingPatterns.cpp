#include "stdafx.h"

int main() 
{
#ifdef COMMAND_PATTERN
    AlphaUser alpha("Alpha");
    BravoUser bravo("Bravo");

    InputMap* inputMap = new InputMap();
    inputMap->handle("charge", alpha);
    inputMap->handle("retreat", bravo);
    inputMap->handle("stab", alpha);
    inputMap->handle("unknown", bravo);

    delete inputMap;
#endif

    return 0;
}
