// mine16.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
You are in a large open area within the mine.  This is where the activity, and the gnomes, are concentrated.  Ladders line the walls and gnomes are mining the gems and metals from the stone.  Torches burn brightly here, light reflecting off the walls and carts.  Piles of rock line the floor along the walls.
NEWBIE
    );
    set_exits(([
        "west":HILL"mine15",
        "south":HILL"mine20",
        "east":HILL"mine17",
        "north":HILL"mine11",
    ]));
    add_item("piles","Several gnomes are sifting and sorting through the rubble from the mining, occasionally dodging falling rock from above.");
}
