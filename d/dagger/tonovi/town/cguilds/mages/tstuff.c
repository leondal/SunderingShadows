// Wizbam Redux, Tower of the Arcane, Tabor
// Tabor
// tfloor4.c

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Book Seller, Marble Academy, Tonovi");
    set_short("Book Seller, Marble Academy, Tonovi");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_long("Generic description for the Mage's Book Seller, Marble Academy, Tonovi.");
    set_light(2);
    set_indoors(1);
    set_smell("default","You smell old, dusty parchment.");
    set_listen("default","You hear the mumblings of apprentices "+
        "working in the back of the store.");
     set_exits( ([
        "north" : "tfloor4",
        ]) );
}

void reset()
{
    ::reset();
/*
    if(!present("wizbam"))
        find_object_or_load(MONDIR+"wizbam")->move(TO);
*/
}
