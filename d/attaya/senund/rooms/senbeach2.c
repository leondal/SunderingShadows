#include <std.h>

inherit ROOM;
#include "../areadefs.h"

void create() {
    ::create();
    set_terrain(HUT);
    set_travel(FRESH_BLAZE);
    set_property("light",2);
    set_property("outdoors",1);
    set_short("Sandy beach on the Isle of Attaya.");
    set_long("
    You are standing on the beach. On an island to the south of you is the
city of Seneca. Palm trees are present every now and then. A cool breeze
can be felt here in the shade.  The beach is very wide here.  The sand 
gives way beneath your feet making your ankles grow tired quickly. The 
coastline of the beach continues to the west here. You can here little 
except for the bellowing of the wind.
");

     set_listen("default","The wind gusts loudly here.");

    set_exits(([

       "northeast" : ROOMS+"beach19",
       "west" : ROOMS+"senbeach3"

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet "+
         "tall, are bending in the powerful winds that rip over the "+
         "island.",
         "beach" : "The beach here is rippled from the effects of a "+
         "recent tide.  The sand is very finely granulated.",
    ] ));
}
