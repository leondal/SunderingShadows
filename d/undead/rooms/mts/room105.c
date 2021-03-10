#include "../../undead.h"

inherit INH+"mts_three.c";

void create() 
{
    ::create();

    set_exits(([
        "west":MTS+"room104",
        "down":DES+"desert_0,6"
             ]));

}
