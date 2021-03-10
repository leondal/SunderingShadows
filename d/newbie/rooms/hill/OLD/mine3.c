// mine3.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
The walls of the mine here are rough but worn, as if they were mined long ago.  Gnomes pass through the area, looking at you a little strangely, probably wondering what you are doing here.  Torches light the way through the mine.  Full carts pass through from the south, heading for the entrance to the mine.
NEWBIE
    );
    set_exits(([
        "east":HILL"mine4",
        "south":HILL"mine8",
    ]));
}
