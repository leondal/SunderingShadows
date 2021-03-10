// mine22.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
Torches provide light for maneuvering here.  Gnomes walk through the area, some looking at you strangely and then hurrying off.  Empty carts are being pulled through the mine to the west, occasionally backing up in a line.  The ceiling is lower here deeper in the mine and the walls are rough.  You see a few ladders leaning against the walls and some piles of rocks.  To the west the mine opens into a large area.
NEWBIE
    );
    set_exits(([
        "east":HILL"mine23",
        "west":HILL"mine21",
    ]));
}
