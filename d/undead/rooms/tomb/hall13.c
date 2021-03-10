#include "../../undead.h"

inherit INH+"tomb_three.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :HALL+"hall11",
        "south"     :HALL+"hall18"
             ]));

}

