#include <std.h>
#include "../../undead.h"

inherit INH+"tomb_five.c";

void create() 
{
    ::create();

    set_long("%^BLUE%^You are in a faintly lighted Chamber\n" + ::query_long() + 
        "  To the north you see another similar chamber.");
 
    set_exits(([
        "south"     :HALL+"chamber6",
        "north"     :HALL+"stair3"
             ]));

}
