#include <std.h>
#include <objects.h>
#include "/d/guilds/pack/short.h"



inherit ROOM;

void create() {
    ::create();
   set_terrain(BARREN);
   set_travel(PAVED_ROAD);
    set_property("light",3);
    set_property("indoors",0);
    set_short("%^BOLD%^%^RED%^Stone Pier on the Sea of Fire%^RESET%^");
    set_long(
@SEETH
%^BOLD%^RED%^You are standing on a Black stone pier%^RESET%^
 %^RED%^The area is extremely smoky you can barely see in front of you. As you reach the end of the pier, you view the area and see faint movement of the water which seems to carry the fire to the endless sea. As you continue to look around you bump into an iron pole that is attached to the pier.
SEETH
);
     set_listen("default","The churning sea of fire is deafening.");
   set_smell("default","You are forced to cover your nose and mouth as the smoke burns them.");
 
    set_exits(([

     "out" : "/d/dagger/marsh/path8",

    ] ));
    set_items(([
      "pole" : "The iron pole is attached to the stone pier. At the top of the iron pole is a bell.",
        "bell" : "Looks like a bell that can be rung.",
         "pier" : "Standing and enduring the oceans torture has seriously compromised the structural integrity of the pier...  In other words...  %^RED%^It would be wise to get off as soon as possible.",
    ] ));
}
void init() {
  ::init();
    add_action("ring","ring");
}
int ring(string str){
    if(!str) {
      write("what?");
      return 1;
    }
    if(str == "bell") {
      write("%^RED%^You ring the bell.");
    TP->move_player(HALL "firedock2.c");
      return 1;
    }
}
