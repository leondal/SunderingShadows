#include "../../undead.h"

inherit INH+"tomb_three.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :HALL+"hall14",
        "east"      :HALL+"hall11"
             ]));

}
