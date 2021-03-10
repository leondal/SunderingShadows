// mine15.c

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
        "east":HILL"mine16",
        "south":HILL"mine19",
    ]));
    add_item("piles","Several gnomes are sifting and sorting through the rubble from the mining, occasionally dodging falling rock from above.");
}
