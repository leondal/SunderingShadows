#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, north gate road.");
    set_long(""
"%^BOLD%^WHITE%^You are on a paved road.\n%^RESET%^"
"The road has been freshly paved, and is still a little soft.  The road "
"molds to your feet as you walk over it, and it makes your feet feel good.  "
"To the south is the center of Sandy, where local people meet to talk.  To the "
"east is the general store of Sandy, where you can buy and sell things.  "
"To the far north is the north gate of Sandy, which leads to the great castle.  "
""
""
"");

     set_listen("default","You hear noises from the east.");
     set_smell("default","You smell something to the south.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy12",
       "south" : "/d/mine2/sandy/room/sandy14",
       "east" : "/d/mine2/sandy/room/general_st",
  
    ] ));
    set_items(([
         "road" : "The road is so new, that is molds to your feet.",
         "castle" : "The castle stands high abovce everything in the distance.",
         "molds" : "They are of peoples feet when they have traveled this road.",
         "feet" : "The are some what black from the pavement.",
    ] ));
}
