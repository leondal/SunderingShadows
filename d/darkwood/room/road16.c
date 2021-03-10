// Written by ShadowGate RoomMaker 1.3 for Macintosh.
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit ROOM;

void create() {
    room::create();
    set_terrain(HILLS);
    set_travel(RUTTED_TRACK);
    set_property("light",2);
    set_property("indoors",0);
    set_short("%^BOLD%^%^BLACK%^Ynt%^RESET%^%^GREEN%^a%^GREEN%^l%^GREEN%^a %^BLACK%^Pass");
    set_name("The Royal Southern Road");
    set_long(
"%^GREEN%^You find yourself on a wide %^GREEN%^r%^GREEN%^o%^BOLD%^%^BLACK%^ad%^RESET%^%^GREEN%^ running to the west and curving tothe south. Looking at the road, you notice that it has been well rutted, and is most certainly a major trade route between the City of Shadow and the domains to the south. To the west, you notice that the road startsto get a bit wider as it moves towards the great city."

    );
     set_smell("default","You smell the scent of a forest in the distance.");
   set_listen("default","The road is quiet except for the occasional sounds of travelers.");
    set_exits(([
      "west" : "/d/darkwood/room/road15",
       "south" : "/d/tharis/road/road1"

    ] ));
    set_items(([
       "road" : "You notice that the road is well-rutted from many wagons passing over it."

    ] ));
//    if(!random(3)) new("/d/laerad/mon/assassin")->move(this_object());
}
void clean_up(){return 1;}
