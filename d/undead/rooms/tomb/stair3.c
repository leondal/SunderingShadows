#include "../../undead.h"

inherit INH+"tomb_four.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :HALL+"chamber5",
        "down"      :HALL+"stair2"
             ]));

}
