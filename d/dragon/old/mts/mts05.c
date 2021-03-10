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
       "west":"/d/dragon/mts/mts06",
       "north":"/d/dragon/mts/mts09",
       "southwest":"/d/dragon/mts/mts04"
    ] ));
    set_invis_exits(({"north","west"}));
    set_items(([                     
       "path":"A small path through the peaks of the northern mountains.",
       "forest":"The northern pines.  It is not a very well traveled place."
    ] ));
}
