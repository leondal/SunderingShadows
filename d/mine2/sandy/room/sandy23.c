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
"You can see the center of Sandy to the far east.  To the far west is the " 
"great ocean.  The road is very new, and your feet still stick to it a little.  "
"There are tall trees that line the sides of the road, and the wind blows gently "
"in this area, creating a relaxing environnment."
""
""
""
"");

     set_listen("default","You hear the wind blow stofly.");
     set_smell("default","You smell the ocean.");
    set_exits(([


       "east" : "/d/mine2/sandy/room/sandy19",
       "west" : "/d/mine2/sandy/room/sandy25",
    ] ));
    set_items(([
         "ocean" : "The ocean is far to the west.",
         "trees" : "They stand tall and strong.",
         "pavement" : "It is very sticky.",
         "road" : "This road has been very well paved.",
    ] ));
}
