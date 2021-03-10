#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Northern Mountains");
    set_long("%^BLUE%^%^BOLD%^
This is a lonely trail through the Northern Mountains.  All around you snow    
blows this way and that.  You don't really know which way you're walking, for
all the snow falling covers your footsteps.
    ");
    set_exits(([
       "west" : "/d/dragon/mts/mts07",
       "east" : "/d/dragon/mts/mts05"
    ] ));
    set_invis_exits(({"east","west"}));
    set_items(([                     
       "path":"A small path through the peaks of the northern mountains.",
       "forest":"The northern pines.  It is not a very well traveled place."
    ] ));
}
