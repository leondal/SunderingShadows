#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",-2);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the sewers under the city of Sanctuary.  You are climbing
a bolted ladder through the mechanical passage that either leads to
the upper stories of the sewers, or down into the sewage pool, some
40 ft. below you.  The walls are covered with some kind of slime mold
from the many decades of sewage that flowed these dark tunnels.
    ");
    set_exits(([
       "down" : "/d/dragon/sewer/tunnel02",
       "up" : "/d/dragon/sewer/sewer20"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_smell("default","The rotting smell of waste is very strong in these tunnels.");
}
