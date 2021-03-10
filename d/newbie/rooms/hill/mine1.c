// mine1.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
You are at the entrance of the mine. There are many carts here waiting to be filled and others waiting to be taken away. Many gnomes wander around the area, looking at you a little strangely, probably wondering what you are doing here. Light streams into the entrance of the mine, causing a few spots in the walls to sparkle in the light.
NEWBIE
    );
    set_exits(([
        "north":FROAD+"20",
        "south":HILL"mine2",
    ]));
}
