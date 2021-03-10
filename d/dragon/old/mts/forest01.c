#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Northern pines");
    set_long("%^BLUE%^%^BOLD%^
These are the great northern pines, with their branches heavily laden with 
snow, almost completely blocking your view of the gray sky above.  Beneath
the sweeping branches, the trail winds among the trunks of the trees.
    ");
    set_exits(([
       "north" : "/d/dragon/mts/forest02",
       "south" : "/d/dragon/forest/forest49"
    ] ));
     set_listen("default","It is still and quiet here among the trees.");
    set_items(([
       "path":"A small path through the huge trees of the northern pine.",
       "forest":"The northern pines.  It is not a very well traveled place."
    ] ));
}
