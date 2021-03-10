#include "../../undead.h"

inherit INH+"tomb_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :HALL+"temproad4",
        "south"     :HALL+"temproad2"
             ]));

}
