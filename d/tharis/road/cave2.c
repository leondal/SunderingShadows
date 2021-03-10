#include <std.h>

inherit ROOM;

void create(){
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(SLICK_FLOOR);
    set_property("no teleport", 1);
    set_property("light", 1);
    set_property("indoors", 1);
    set_short("A dark cave");
    set_long(
      "This dark cave, long left unnoticed in the woods of the road between Tharis and Azha.  The cave leads slowly underground and away from the road, its floors and walls slick with water."
    );
    set_listen("default", "You hear water dripping into pools in the distance.");
    set_smell("default", "The musty smell of a long empty cave floats to your nose");
    set_items( ([
      "walls" : "These walls glisten in the light from the water.",
      "water" : "The water is on the walls.",
    ]) );
    set_exits( ([
      "southeast" : "/d/tharis/road/cave3",
      "north" : "/d/tharis/road/cave1",
    ]) );
}
