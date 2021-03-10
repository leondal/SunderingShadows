#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, stone road.");
    set_long(""
"%^BOLD%^WHITE%^You are on a stone road.\n%^RESET%^"
"The road has been laid with great stones, to keep it in good shape with all "
"the traveling that is done on it.  There is a large bridge to the north, and "
"another stone road to the west.  There are many large stones that lay on the "
"side of the road because they did not need them for this great road.  "
"To the far west is a large ocean were you can see many ships out on it."
"");

     set_listen("default","You hear the stones crack in the sun.");
     set_smell("default","You smell hot stones.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy21",


       "west" : "/d/mine2/sandy/room/sandy24",
    ] ));
    set_items(([
         "stones" : "They are used for the road, and others are just sitting around.",
         "road" : "The road is made of great stones.",
         "ocean" : "The ocean is far away, and is very dangerous.",
         "bridge" : "The bridge is to the north.",
    ] ));
}
