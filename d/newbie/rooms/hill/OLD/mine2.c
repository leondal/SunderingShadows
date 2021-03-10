// mine2.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
You are within sight of the mine's entrance.  Many gnomes wander around
the area, looking at you a little strangely, probably wondering what you
are doing here.  The ceiling is surprisingly high considering the size
of the gnomes that work here.  Torches give off light at night when the
sun does not reach into the mine.
NEWBIE
    );
    set_exits(([
        "north":HILL"mine1",
        "south":HILL"mine5",
    ]));
}
