#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Small room");
   set_short("Small room");
   set_long("%^BOLD%^Small room%^RESET%^\n"
"This little, dingy room with grimy walls.  There are two small beds here, little more than padded hammocks, "
"one against the wall on either side of the room.  There isn't much other space to move in here.  The floor, "
"walls and roof are all made of the same old %^ORANGE%^wood%^RESET%^, creaking as the boat rocks on the "
"water.  There's only one small, circular window here, covered in%^BLACK%^%^BOLD%^ dirt%^RESET%^, that sheds "
"faint light around the room.  A large doorway leads out into the corridor.\n");
   set_smell("default","You smell fresh ocean air minced with the smell of charred wood.");
   set_listen("default","You hear the boards of the ship creak in an unsettling way.");
   set_items(([
     ({"floor","walls","roof","wood"}):"The floor, walls and roof are all made of the same old%^ORANGE%^ "
"wood%^RESET%^, that creaks as the ship moves.  The wood looks quite old, and is in desperate need of a "
"polish.",
     "doorway":"The single outlined doorway leads back out into the corridor.",
     "window":"The lone circular window is covered in %^BLACK%^%^BOLD%^grime%^RESET%^, preventing much light "
"from being shed into the room.",
     "shadows":"The room is shrouded in %^BLACK%^%^BOLD%^shadow%^RESET%^, making it hard to distinguish "
"details of the area around you."
   ]));
   set_exits(([
     "west":COVE"boata05"
   ]));
}

void reset() {
   if(!has_mobs()) {
     if(mons) mons = ([]);
     switch(random(3)) {
       case 0..1:
       set_monsters(({MON"secondmate",MON"piratecrew"}),({1,1}));
       break;
       case 2:
       set_monsters(({MON"secondmate",MON"piratecrew2"}),({1,1}));
       break;
     }
   }
   ::reset();
}
