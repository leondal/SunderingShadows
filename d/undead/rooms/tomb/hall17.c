#include "../../undead.h"

inherit INH+"tomb_three.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :HALL+"hall18",
        "west"      :HALL+"hall16"
             ]));

}

