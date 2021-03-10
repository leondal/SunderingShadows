#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(HUT);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("indoors",1);
    set_short("Under the boardwalk.");
    set_long("
    You are standing beneath a wooden pier that leads south over the ocean to the city of Seneca.  A cool breeze can be felt here in the shade.  The beach is very wide here.  The sand gives way beneath your feet making your ankles grow tired quickly.
    You can see an opening in the fence to the east.
");

     set_listen("default","The waves pound against the rocky coastline coating you in a fine mist of seaspray.");
 
    set_exits(([

       "west" : "/d/attaya/beach18",
       "east" : "/d/attaya/beach20",

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet tall, are bending in the powerful winds that rip over the island.",
         "fence" : "It is a chipping, fading, white fence.  It has been erected at the dune line.",
         "beach" : "The beach here is rippled from the effects of a recent tide.  The sand is very finely granulated.",
    ] ));
}
