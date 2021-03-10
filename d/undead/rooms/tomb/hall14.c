#include "../../undead.h"

inherit INH+"tomb_three.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :HALL+"hall12",
        "south"     :HALL+"hall15"
             ]));

}

