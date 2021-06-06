// Level 4 Landing in the Marble Academy, Tonovi
// tfloor4.c

#include <std.h>

inherit VAULT;

void create()
{
    ::create();
    set_name("Floor 4");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_name("Level 4 Landing in the Marble Academy, Tonovi");
    set_short("Level 4 Landing in the Marble Academy, Tonovi");
    set_long("Generic description for the Level 4 Landing, Marble Academy, Tonovi.");
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","A number of strange smells are coming from the north.");
    set_listen("default","You hear some muted explosions behind the door to the north.");
    set_exits( ([
        "north" : "tlab",
        "south" : "tstuff",
        "down"  : "tfloor3",
    ]) );
    set_door("door","tlab","north");
    set_open("door", 0);
}
