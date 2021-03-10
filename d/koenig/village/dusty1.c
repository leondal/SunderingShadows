//updated to reflect move of Koenig.  Should be changed to a new dir.  Circe 11/29/03
#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(HILLS);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",0);
    set_short("A dusty road");
    set_long(
@KAYLA
Here, the mountains flatten out into large hills, giving way for a 
large road to pass through.  The air is thin here, and becomes dryer
the farther east you travel, the greens becoming browns.  
KAYLA
    );
     set_smell("default","The earthy scent of the fields rises on the mountain air.");
     set_listen("default","You hear the gentle rustling of the wind.");
    set_exits(([
       "west" : "/d/shadow/room/pass/pass16",
       "east" : "/d/koenig/village/dusty2"
    ] ));
    set_items(([
       "road" : "A long, dusty road, leading across the cornfields."
    ] ));
}

void init() {
  ::init();
}
