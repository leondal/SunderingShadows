// mine7.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
The walls of the mine here are rough but worn, as if they were mined long ago.  There is little activity of any kind here other than carts pulling out of the way of the entrance.
NEWBIE
    );
    set_exits(([
        "east":HILL"mine7",
        "west":HILL"mine5",
    ]));
}
