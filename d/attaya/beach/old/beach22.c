#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(BEACH);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Sandy beach on the Isle of Attaya.");
    set_long("
   The beach narrows in at this point, and the ocean nearly extends all the way into the jungle.  A few palm trees are even growing out past the waterline.
    The city of Seneca can be seen across a channel of water to the southeast.
    A couple gulls perched within one of them squawk at you as you pass.
");

    set_listen("default","The ocean roars around you and the pathetic cries of a couple of gulls is nearly drowned out.");
 
    set_exits(([

       "northeast" : "/d/attaya/beach23",
       "southwest" : "/d/attaya/beach21",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.  A couple of them have been surrounded by the sea as it claims another portion of Attaya..",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
    ] ));
}
