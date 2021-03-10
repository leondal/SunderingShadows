#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, east road.");
    set_long(""
"%^BOLD%^WHITE%^You are on a paved road.\n%^RESET%^"
"You can see the center of Sandy to the west.  To the far east is the " 
"east gate of Sandy.  This road has is starting to wear out and become tattered  "
"in many places.  There are many spots of the road that have holes, and allready "
"need to be patched by the towns road builders."
""
""
""
"");


     set_smell("default","You fresh air.");
    set_exits(([


       "east" : "/d/mine2/sandy/room/sandy5",
       "west" : "/d/mine2/sandy/room/sandy14",
    ] ));
    set_items(([
         "road" : "The road is new, but allready has holes in it.",
         "holes" : "They are just small ones right now.",
         "pavement" : "It is worn out.",
         "zeek" : "Zeek made this town!",
    ] ));
}
