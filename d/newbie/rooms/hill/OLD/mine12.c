// mine12.c

#include "../../newbie.h";

inherit MINE;

void create(){
    ::create();
    set_long(
@NEWBIE
Torches provide light for maneuvering here. A few gnomes hurry through the area, glancing at you questioningly then continuing on. Empty carts are being pulled through the mine to the east. This part of the mine appears to be used as storage for unused mining equipment.
NEWBIE
    );
    set_exits(([
        "north":HILL"mine10",
        "east":HILL"mine13",
    ]));
    add_item("equipment","Carts awaiting repair, extra mining tools, ladders, and torches line the walls.");
}
