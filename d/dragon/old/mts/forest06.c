#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Northern pines");
    set_long("%^BLUE%^%^BOLD%^
You find yourself before a square, four-story structure, solidly made
of brick, with high wooden gables.  A painted sign hanging over the door
depicts a grapevine wound around a horeshoe.  Many windows dot the walls,
but only those on the first floor are lit.  Shadowy silhouettes move
upon the unpolished glass.
    ");
    set_exits(([
       "enter" : "/d/dragon/mts/inn",
       "west" : "/d/dragon/mts/forest05"
    ] ));
    set_listen("default","It is still and quiet here among the trees.");
    set_items(([
       "path":"A small path through the huge trees of the northern pine.",
       "forest":"The northern pines.  It is not a very well traveled place."
    ] ));
}
