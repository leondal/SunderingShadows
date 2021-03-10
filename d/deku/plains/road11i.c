#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_property("light" , 1);
    set_property("indoors" , 0);
    set_short("Forest Road");
    set_terrain(HEAVY_FOREST);
    set_travel(GAME_TRACK);
    set_long( (: TO,"ldesc" :) );
    set_exits(([
        "west" : "/d/deku/plains/road12",
        "south" : "/d/deku/plains/road10"
   	]));
    set_listen("default", "The forest is eerily quiet here.");
    set_smell("default", "The decaying vegetation gives off an unhealthy smell.");

}

string ldesc(string str) {
   return("%^BOLD%^Forest Road%^RESET%^\n"
     "An old footpath continues through this portion of the forest, which "
     "becomes progressively darker.  The trees and vegetation have twisted "
     "around each other, forcing you to slash through the brush and yet "
     "it's hard to find living plants.  It is as if the forest is poisoned "
     "and struggles to find release.");
}
