// mine5.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
You can see a slight lightening to the north, toward the mine's entrance.  Torches provide light for maneuvering here. Gnomes wander through the area, looking at you a little strangely, probably wondering what you are doing here.  Carts are moving freely through this intersection of paths.
NEWBIE
    );
    set_exits(([
        "north":HILL"mine2",
        "east":HILL"mine6",
        "south":HILL"mine10",
        "west":HILL"mine4",
    ]));
}
