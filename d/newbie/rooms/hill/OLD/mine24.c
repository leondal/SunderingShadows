// mine24.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
Torches provide light for maneuvering here.  A few gnomes hurry through the area, glancing at you questioningly then continuing on.  Empty carts are being pulled through the mine to the west.  The ceiling is lower here deeper in the mine.
NEWBIE
    );
    set_exits(([
        "north":HILL"mine18",
        "west":HILL"mine23",
    ]));
}
