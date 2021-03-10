#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, south road.");
    set_long(""
"%^BOLD%^WHITE%^You are on a paved road.\n%^RESET%^"
"This road is very odd, because there is not much to see, or places to go.  "
"To the north is the the middle of Sandy, and to the south are some more shops.  "
"There are large trees that block your view of the town, but you can tell that "
"the town is large, just from the nice roads here.  There are small pieces of "
"rock, laying on the road, that apear to be there just to trip people as they "
"come by.");

     set_listen("default","You hear the wind blow in the trees.");
     set_smell("default","You smell many things.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy15",
       "south" : "/d/mine2/sandy/room/sandy17",


    ] ));
    set_items(([
         "trees" : "The trees are palm trees that are blocking your view of the area.",
         "rocks" : "They apear to be placed here by someone who want to trip you.",
         "shops" : "They are all over the city.",
         "road" : "The road is paved, and is covered with rocks.",
    ] ));
}
