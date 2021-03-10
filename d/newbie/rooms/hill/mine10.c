// mine10.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
You can see a slight lightening to the north, toward the mine's entrance.  Torches provide light for maneuvering here. Gnomes wander through the area, looking at you a little strangely, probably wondering what you are doing here.  Empty carts are pulled through the mine to the south.
NEWBIE
    );
    set_exits(([
        "north":HILL"mine5",
        "south":HILL"mine12",
        "west":HILL"mine9",
    ]));
}
