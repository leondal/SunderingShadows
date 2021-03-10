#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_INT_BASE;

string long_desc();

void create() {
  
  ::create();
  set_short("grand chamber");
  set_items(([  ({"shelf", "stone shelf"}): "The shelf is set at about"
                 +" waist height to a human. Its surface is stained with"
                 +" many dark blotches.",
                ({"stair", "stairs"}): "The stairs lead upwards towards a"
                +" dim light. A dark space sits below them",
                  "space" : "It's dark there, behind the stairs"
  ]) );
  set_exits( ([ "east" : ROOMS + "corridor2" ,
                "west" : ROOMS + "corridor6" ,
 //               "south": ROOMS + "guardcham",
                "up" : ROOMS + "processional",
                "curtain": ROOMS + "vestibule" ])  );
	set_invis_exits( ({"curtain"}) );
  set_door("damaged door",ROOMS+"corridor2","east",0);
  set_door("door",ROOMS+"corridor6","west",0); 
  set_door("double doors",ROOMS+"guardcham","south",0); 
  set_door_description("double doors","A grand set of stone double doors,"
                                     +" set beneath massive stone"
                                     +" frames.");
  set_door_description("door","A heavy stone door.");
  set_door_description("damaged door","A heavy stone door, which has sustained heavy damage.");
  set_search("space","You find a %^ORANGE%^curtain%^RESET%^ in the north"
                    +" wall, hidden in the dark space behind the stairs."
                    +" You could probably go through it.");
  set_search("stairs","There is a dark space behind the stairs. It looks"
                     +" interesting.");
}



string long_desc(){
    return "A large, square chamber, with a set of stone stairs leading"
          +" up, positioned by the north wall. There are doors at the"
          +" southern end of the east and west walls. Along the south"
          +" wall there is a stone shelf, supported by sturdy pillars.";
}
