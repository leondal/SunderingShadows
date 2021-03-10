// mine7.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_light(1);
    set_long(
@NEWBIE
The walls of the mine here are rough but worn, as if they were mined long ago.  There is little activity of any kind here and there are no torches on the walls.
NEWBIE
    );
    set_exits(([
        "west":HILL"mine6",
    ]));
}
