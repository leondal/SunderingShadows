#include "../../undead.h"

inherit INH+"tomb_three.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :HALL+"hall14",
        "east"      :HALL+"hall16"
             ]));

}

