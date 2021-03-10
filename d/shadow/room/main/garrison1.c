// Garrison Road, Shadow
// Thorn@ShadowGate
// 970215
// City of Shadow 1997 revision
// This room conforms to Phase I switchover

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
men run in a steady stream to and from the north.  
  As you might expect, the city keeps a substantial garrison 
nearby to prevent disturbances from arising inside the walls.
The entrance to one of these is located to the east of where
you are standing.
  Garrison Road continues to the north and south.
AZHA
    );
	set_exits(([
        "south" : "/d/shadow/room/main/garrison2",
        "north" : "/d/shadow/room/main/northcross",
  "east" : ROOMDIR+"troopb3",
  ] ));     
  set_smell("default","You smell the cool fresh air.");
  set_listen("default","You hear the sounds of people moving around the city.");
}
void reset(){
   if(!present("street_light",TO))
      new(MISCDIR+"street_light")->move(TO);
}
