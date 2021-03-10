#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_name("Forest Road");
    set_short("Forest Road");
    set_terrain(HEAVY_FOREST);
    set_travel(DIRT_ROAD);
    set_long( (: TO,"ldesc" :) );
    set_listen("default", "The forest is eerily quiet here.");
    set_smell("default", "The decaying leaves create a musty smell.");
    set_exits(([
        "north" : "/d/deku/plains/road09",
        "south" : "/d/deku/plains/road07"
   	]));
}

string ldesc(string str) {
   return("%^BOLD%^Forest Road%^RESET%^\n"
     "This dirt road leads through the seemingly quiet forest.  You notice "
     "that the forest is beginning to get more dense as you walk and "
     "somewhat down the path it begins to become darker.");
}
