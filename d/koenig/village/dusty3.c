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
the farther east you travel, the greens becoming browns.  Farther to 
the east, you can see cornfields rising over the rolling hills.  A 
great wooden hall is lodged here in the foothills, fortified by high 
walls on all sides.
KAYLA
    );
     set_smell("default","The earthy scent of the fields rises on the mountain air.");
     set_listen("default","The almost constant sound of battle rings out from beyond the walls.");
    set_exits(([
      "west" : "/d/koenig/village/dusty2",
//       "north" : "/d/koenig/village/house1",
//       "south" : "/d/koenig/village/dusty6",
       "east" : "/d/koenig/village/dusty4",
      // "temple" : "/d/magic/temples/varda/varda",
    ] ));
    set_items(([
       "road" : "A long, dusty road, leading across the cornfields."
//       "house" : "A large wooden house.  Looks empty."
    ] ));
}
