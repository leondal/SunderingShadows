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
"You can see the center of Sandy to the far west.  To the east is the " 
"east gate of Sandy.  This road has been traveled alot from the worn out pavement.  "
"The great city gate to the east stands tall enough you can see it very well from "
"this area, and it looks like it could keep anyone or anything out that the towns "
"people want."
""
""
"");


     set_smell("default","You fresh air.");
    set_exits(([


       "east" : "/d/mine2/sandy/room/sandy3",
       "west" : "/d/mine2/sandy/room/sandy6",
    ] ));
    set_items(([
         "road" : "The road is new, but allready worn out.",
         "gate" : "The gate stands tall to the east.",
         "pavement" : "It is worn out.",
         "air" : "The air is very clean.",
    ] ));
}
