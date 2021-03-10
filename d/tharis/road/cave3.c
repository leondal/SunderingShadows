#include <std.h>

inherit ROOM;

void create(){
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(SLICK_FLOOR);
    set_property("indoors", 1);
    set_property("light", 1);
    set_property("no teleport", 1);
    set_short("A dark cave");
    set_long(
      "This dark cave, far from the path between tharis and azha, has led deep underground.  Here at the bottom of the cave you are now standing in ankle high water, building here for years.  The water chills you to the bone as it seeps through your boots."
    );
    set_listen("default", "You hear water dripping into pools in the distance.");
    set_smell("default", "The musty smell of a long empty cave floats to your nose");
    set_items( ([
      "walls" : "These walls glisten in the light from the water.",
      "water" : "The water is on the walls.",
    ]) );
    set_exits( ([
      "northwest" : "/d/tharis/road/cave2",
    ]) );
}
