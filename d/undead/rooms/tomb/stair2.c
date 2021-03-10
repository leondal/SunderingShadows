#include "../../undead.h"

inherit INH+"tomb_four.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :HALL+"hall11",
        "up"        :HALL+"stair3",
        "down"      :HALL+"stair"
             ]));

}
