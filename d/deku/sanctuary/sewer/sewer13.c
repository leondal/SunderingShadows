#include <std.h>
#include "../dragon.h";

inherit BSEWER;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long(
    "%^BOLD%^%^BLACK%^These are the disgusting sewers under the city of Sanctuary. They are"+
    " filled with many strange fobjects. The tunnel branches here, it contines"+
    " to the east, south and west. The dark walls are covered with disgusting"+
    " slime mold from the many decades of sewage that remain here."
    );
    set_exits(([
       "east" : SEWER+"sewer12",
       "south" : SEWER+"sewer21",
       "west" : SEWER+"sewer14"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
}

