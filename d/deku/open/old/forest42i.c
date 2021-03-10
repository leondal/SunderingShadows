#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Shadowlord forest");
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_long( (: TO, "ldesc" :) );
    set_listen("default","Peculiar, the forest is deadly quiet.");
    set_smell("default","You smell the decay of fallen leaves and branches.");
    set_exits(([
       "west" : "/d/deku/open/forest46",
       "east" : "/d/deku/town/road1"
    ] ));
    set_items(([
    ] ));
}

string ldesc(string str) {
   return("%^ORANGE%^All around you, fog blankets the forest like a dark gray "
     "cloak.  A thin, clinging mist dampens your skin and everything around you.  "
     "Shadows seem to dart through the fog and trees.  The trees look ancient "
     "with their knotted limbs and faded leaves, looking withered and half "
     "dead.  You see few signs of wildlife and even the flowers refuse to bloom "
     "in this section of the forest.\n");
}
