#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
    ::create();
    set_travel(DIRT_ROAD);
    set_terrain(HEAVY_FOREST);
    set_property("indoors",0);
    set_property("light",1);
    set_short("%^BOLD%^%^GREEN%^A Path Through The Forest%^RESET%^");
    set_long(query_short() + "\n%^GREEN%^All around you, tall pine and majestic oak trees "+
        "rise up and block out the majority of "+
        "the light from above, leaving you little question as to why "+
        "they call it the Darkwood Forest.  A carpet of pine needles "+
        "stretches out and away from the path.  Signs of wildlife are "+
        "everywhere...birds sing merrily from their perches, and the bushes "+
        "rustle all around you as small creatures scurry about.  "+
        "The path you are on seems to continue southeast and northwest from here, "+
        "hopefully providing you with safe passage through the forest.");
    set("night long","Very little of the moonlight manages to find its "+
        "way down to your level, leaving you in almost total darkness.  "+
        "Trees rise ominously around you, making you feel as if you're "+
        "in a closet instead of the open wilderness.  An owl hoots in "+
        "the distance, startling a small creature in the bushes a little "+
        "ways ahead of you.  As best you can tell, the path stretches "+
        "to the northwest and east of here.");
    set_smell("default","The crisp, fresh scent of pine fills the air.");
    set_listen("default","The trees creak as they sway in the wind.");
    set_items(([
        ({"tree","trees","pine","oak"}):"Huge, sprawling oak trees fight "+
        "for space amongst the tall pine trees.",
        "path":"This small dirt path is rather easy to follow, given it is "+
        "the only part not covered in pine needles."
    ]));
}

