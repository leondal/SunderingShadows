#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Shadowlord forest");
    set_long( (: TO, "ldesc" :) );
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_listen("default","Peculiar, the forest is deadly quiet.");
    set_smell("default","You smell the decay of fallen leaves and branches.");
    set_exits(([
       "north" : "/d/deku/open/forest3",
       "south" : "/d/deku/open/forest1"
    ] ));
    set_items(([
    ] ));
}

string ldesc(string str) {
   return("You are on a path within the Shadowlord forest.  The forest here is "
     "somewhat healthier than most of the island somehow, as if a force is "
     "fighting the evil and decay.  The road seems to continue northward into "
     "the darkness of the fog that blankets most of the the island like a dark "
     "gray cloak while to the south is the sea.");
}
