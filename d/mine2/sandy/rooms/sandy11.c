#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, north gate road");
    set_long(""
"%^BOLD%^WHITE%^You are a paved road.\n%^RESET%^"
"The road has just been paved not to long ago, which makes your feet feel "
"better as you walk over it.  To the north is the north gate of Sandy, and to "
"the south is the rest of the city to Sandy.  To the east is the boat shop, "
"where you can purchase a boat to search out islands of the ocean.  There is a "
"small boat yard that you can see in the distance, where they are building "
"large ships.");

     set_listen("default","You hear the wind blowing.");
     set_smell("default","The smell hot pavement.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy12",
       "south" : "/d/mine2/sandy/room/sandy10",
        "east" : "/d/mine2/sandy/room/boat",

    ] ));
    set_items(([
         "road" : "The road has just been paved.",
         "boat yard" : "The boat yard is far away, and there is no way yo get to it from here.",
         "pavement" : "The pavement is very warm, and it feels good on your feet.",
         "town" : "The town is the great town of Sandy.",
    ] ));
}
