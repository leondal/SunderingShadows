#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Dirty room");
   set_short("Dirty room");
   set_long("%^BOLD%^Dirty room%^RESET%^\n"
"This room is a little larger than the others, though no less dirty.  A bed rests against the far wall, and a small table beside it.  The floor, walls and roof are all made of the same old %^ORANGE%^wood%^RESET%^, creaking as the boat rocks on the water.  The lone window is covered in%^BLACK%^%^BOLD%^ dirt%^RESET%^, that sheds only faint light around the room.  A large doorway leads out into the corridor.\n");
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
     "north":COVE"boata05"
   ]));
}

void reset() {
   if(!has_mobs()) {
     if(mons) mons = ([]);
     switch(random(3)) {
       case 0:
       set_monsters(({MON"piratecaptain",MON"piratecrew",MON"piratecrew2"}),({1,1,1}));
       break;
       case 1:
       set_monsters(({MON"piratecaptain",MON"piratecrew"}),({1,2}));
       break;
       case 2:
       set_monsters(({MON"piratecaptain",MON"piratecrew2"}),({1,2}));
       break;
     }
   }
   ::reset();
}
