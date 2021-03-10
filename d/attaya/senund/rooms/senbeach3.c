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
can be felt here in the shade.  Their is a small cliff coming out of the
beach that blocks off passage to the north. Due to that fact this part of
the beach is rather isolated from the rest. To the west you can see the
beach edge up against the jungle. The waves crash onto the beach just 
south of you. You can hear little except for the bellowing of the wind,
and the crash of the waves.
");

     set_listen("default","The wind gusts loudly here and "+
                "and the waves crash loudly.");
 
    set_exits(([

       "east" : ROOMS+"senbeach2",
       "west" : ROOMS+"senbeach4"

    ] ));
    set_items(([
         "trees" : "Thick palm trees, some standing hundreds of feet "+
         "tall, are bending in the powerful winds that rip over the "+
         "island.",
         "beach" : "The beach here is rippled from the effects of a "+
         "recent tide.  The sand is very finely granulated.",
    ] ));
}
