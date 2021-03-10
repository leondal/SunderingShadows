// mine9.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
The walls of the mine are rough and worn as if it was mined long ago.  There is little activity of any kind here and there are no torches on the walls.  Occasionally a cart pulls aside for repairs.
NEWBIE
    );
    set_exits(([
        "east":HILL"mine10",
    ]));
}
