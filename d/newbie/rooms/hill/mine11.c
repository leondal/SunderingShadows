// mine11.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
The walls of the mine here are rough but worn, as if they were mined long ago.  Gnomes pass through the area, looking at you a little strangely, probably wondering what you are doing here. Torches light the way through the mine.  Full carts pass through from an open area to the south.
NEWBIE
    );
    set_exits(([
        "north":HILL"mine8",
        "south":HILL"mine16",
    ]));
}
