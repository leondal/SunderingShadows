#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();

    set_exits(([
       "east" : F_ROOMS"36-8",
       "north" : F_ROOMS"37-9",
       "south" : F_ROOMS"37-7",
       "southeast" : F_ROOMS"36-7",
       "northeast" : F_ROOMS"36-9",
       "hole" : "/d/deku/forest/koboldshrine",
    ] ));
    set_invis_exits(({"hole"}));
    add_item("hole","%^GREEN%^A hole has been dug in the ground here, sizeable but well hidden amongst the "
"undergrowth and foliage.  Someone seems to have deliberately concealed it.  You're sure you could fit into it "
"and see what it hides within.");
    set_search("default","Perhaps something of interest could have fallen to the ground and mixed with the heavy debris?  You also notice a %^YELLOW%^hole%^RESET%^ among the foliage, well hidden.");
    set_search("hole","%^GREEN%^A hole has been dug in the ground here, sizeable but well hidden amongst the "
"undergrowth and foliage.  Someone seems to have deliberately concealed it.  You're sure you could fit into it "
"and see what it hides within.");
}



