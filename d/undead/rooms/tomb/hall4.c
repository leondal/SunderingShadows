#include "../../undead.h"

inherit INH+"tomb_two";

void create() 
{
    ::create();

    set_exits(([
        "north"     :HALL+"stair",
        "south"     :HALL+"hall3",
        "east"      :HALL+"hall6",
        "west"      :HALL+"hall5"
             ]));

}
