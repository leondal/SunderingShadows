#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_long("%^BOLD%^Forest Road%^RESET%^
An old footpath continues through the bleak landscape.  The trees
and vegetation twists around itself and you find yourself slashing
through the brush.  In the distance are the crumbling stone walls
of the city of Sanctuary.
    ");
    set_exits(([
        "north" : "/d/deku/plains/road35",
        "south" : "/d/deku/plains/road33"
   	]));
}
