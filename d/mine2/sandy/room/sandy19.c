#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, west road.");
    set_long(""
"%^BOLD%^WHITE%^You are on a paved road.\n%^RESET%^"
"To the east is the center of the town Sandy.  To the north is the town " 
"armory where you can buy and sell armor of many types.  To the south is a "
"road that leads to a small building where many magical things take place.  "
"To the far west is the is the boat dock where you can get out onto the great "
"sea."
""
"");

     set_listen("default","You hear the sea in the far west.");
     set_smell("default","You smell salt water.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/armory",
       "south" : "/d/mine2/sandy/room/sandy20",
       "east" : "/d/mine2/sandy/room/sandy14",
       "west" : "/d/mine2/sandy/room/sandy23",
    ] ));
    set_items(([
         "ocean" : "The ocean is far to the west.",
         "dock" : "The dock is far to the west.",
         "sea" : "The sea is far to the south.",
         "road" : "This road has been very well paved.",
    ] ));
}
