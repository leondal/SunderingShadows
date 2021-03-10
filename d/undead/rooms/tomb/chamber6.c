#include <std.h>
#include "../../undead.h"

inherit INH+"tomb_five.c";

void create() 
{
    ::create();

    set_long("%^BLUE%^You are in a faintly lit Chamber\n"
        "%^BOLD%^BLACK%^You stand in a chamber shaped like a perfect cube.  "
        "To the south is a giant metal gate engraved with hundreds of "
        "pictograms. You only wish you could understand what they were "
        "trying to tell you because it's obvious someone spent years putting "
        "then there for a reason. To one side of the door is an equally "
        "exotic iron gargoyle. As you approach the gate it comes to life "
        "and attacks you!");
    
    set_exits(([
        "door":HALL+"chamber7",
        "north":HALL+"chamber5"
             ]));
}

void reset() 
{
    ::reset();
    if(!present("gargoyle")) { new(MON"gargoyle")->move(TO); }
    return;
}
