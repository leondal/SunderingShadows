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
"The road has been made of large stones, and has been travled a lot.  "
"There are several places were the stone has allready started to wear down.  "
"Great trees line the side of the road in a small section, and a large chair is "
"in the middle of where the trees line the road.  There are many large stones "
"left over from when the road was made, and now serve as chairs."
""
"");

     set_listen("default","You hear the stones crack in the hot sun.");
     set_smell("default","You smell hot stones.");
    set_exits(([


       "south" : "/d/mine2/sandy/room/sandy25",
       "east" : "/d/mine2/sandy/room/sandy22",

    ] ));
    set_items(([
         "trees" : "They line the road in a small section.",
         "stones" : "They form the great road.",
         "chair" : "The chair is for some reason you do now know.",
         "road" : "The roads is made of stone.",
    ] ));
}
