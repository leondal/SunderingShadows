// Garrison Road, Shadow
// Thorn@ShadowGate
// 970215
// City of Shadow 1997 revision

#include <std.h>
#include "/d/shadow/room/shadow.h"

inherit ROOM;

void create() {
  ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);  
	set_short("Garrison Road, Shadow");
  set_long(
@AZHA
%^BOLD%^CYAN%^Garrison Road%^RESET%^
  You are on Garrison Road, leading north from the center of the 
great city of Shadow.  	To the north, you can see the busy area
near the North Gate.  Numerous wagons, pedestrians and mounted 
men run in a steady stream to and from the north.  To the south,
you are beginning to be able to see the taller stone buildings in
the center of the city.
  The entrance to a garrison barracks of these is located to the 
west of where you are standing.
  Garrison Road continues to the north and south.
AZHA
    );
	set_exits(([
        "south" : "/d/shadow/room/main/garrison3",
        "north" : "/d/shadow/room/main/garrison1",
  "west" : ROOMDIR+"troopb4"
  ] ));     
  set_smell("default","You smell the cool fresh air.");
  set_listen("default","You hear the sounds of people moving around the city.");
}

void reset(){
   ::reset();
        if(!present("street_light",TO))
                new(MISCDIR+"street_light")->move(TO);
}
