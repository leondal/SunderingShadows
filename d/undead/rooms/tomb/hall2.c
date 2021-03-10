#include "../../undead.h"

inherit INH+"tomb_two";

void create() 
{
    ::create();

    set_exits(([
        "north"     :HALL+"hall3",
        "south"     :HALL+"hall"
             ]));

}
