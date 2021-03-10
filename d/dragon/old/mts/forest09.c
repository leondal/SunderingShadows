#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Northern pines");
    set_long("%^BLUE%^%^BOLD%^
All around you are the thick boughs of the northern pines.  The sky is
barely visible through the snow-laden branches of the towering trees.
Beneath these sweeping branches, the trail winds among the trunks of
the trees leading deeper into the luming forest.
    ");
    set_exits(([
       "south" : "/d/dragon/mts/forest08",
       "northwest" : "/d/dragon/mts/forest10"
    ] ));
     set_listen("default","It is still and quiet here among the trees.");
    set_items(([
       "path":"A small path through the huge trees of the northern pine.",
       "forest":"The northern pines.  It is not a very well traveled place."
    ] ));
}
