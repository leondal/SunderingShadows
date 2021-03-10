// mine4.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
The walls of the mine here are rough but worn, as if they were mined long ago.  Gnomes pass through the area, looking at you a little strangely, probably wondering what you are doing here.  Full carts pass through from the west, heading for the entrance to the mine.  In the torchlight, the contents of the carts sparkle.
NEWBIE
    );
    set_exits(([
        "east":HILL"mine5",
        "west":HILL"mine3",
    ]));
}
