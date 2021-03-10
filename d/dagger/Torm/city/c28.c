#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create()
  {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("indoors",1);
  set_door("door",TCITY+"c27","east","masterkey");
  set_property("light",2);
  set_smell("default","You smell old sweat and decaying food from somewhere behind the counter.");
    set_listen("default","Even these walls can't stop the sound of the waves of the Dagger Sea.");
    set_short("Torm's general store");
  set_long("  This large stone building seems a little out of place in this city."
  "  The windows are small and bars cover them from the inside and you notice the door is much thicker and stronger than it really needs to be."
   "  A few Torm citizens wander through the aisles but you notice there really isn't much here other than the most basic of dry goods."
  "  Most of the things the people need they must buy at the central market place."
  );
   set_items(([
    "windows" : "There are only a few small windows looking out towards the eastern street, but they are covered by thick bars that prevent entrance.",
   "bars" : "Thick iron bars cover the windows in this room, preventing even the tiniest person from squeezing between them, and they look too thick to bend or break.",
   "aisles" : "There are aisles with shelves stocked with various goods. You notice that the store keeper watches everyone closely as they enter, as though he might have a problem with thieves.",
   "floor" : "The floor here is rather dusty and grimy with sea salt, it doesn't get cleaned much.",
   ]));
  set_exits(([
  "east":TCITY+"c27",
  ]));
}
void init(){
  ::init();
  if(!present("jomai",TO)){
  new(MON+"genkeeper.c")->move(TO);
  }
}
