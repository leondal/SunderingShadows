#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create()
  {
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_door("door",TCITY+"c75","east","Torm masterkey");
   set_short("The master blacksmith, Shamus' Armory");
   set_property("indoors",1);
   set_property("light",3);
  set_long(
   "The master blacksmith, Shamus' Armory.\n"
  "  This wide stone building is well lit and very neat."
    "  Many shields hang on the walls and there are various pieces of armor on mounts and mannequins waiting to be repaired or sold."
    "  A great central kiln heats the place, but a breeze through the open door and windows keeps the heat manageable."
   "  The floor is stained with soot in a few places and bears some scorch marks in others.  There is only a simple bench on which customers may sit while they await adjustments to their armor.  Although this place is rather simplistic, Shamus is supposed to be one of the best armorers on the Dagger Sea."
  );
   set_smell("default","The smoke from hot metal hangs in the air.");
   set_listen("default","Apprentices can be heard pounding away at their work in the back somewhere.");
   set_items(([
   ({"shields","pieces of armor","armor"}) : "There are many shields and various pieces of armor hung up on the walls, situated on mounts or mannequins, just waiting to be sold.",
   ({"mounts","mannequins"}) : "There are several mounts and mannequins on which armor is hung in this shop, allowing the potential buyers to see how they might look in it.",
   "floor" : "The floor is relatively neat, but there are several soot stains and scorch marks that are not going to be scrubbed away. While there is an attempt to keep the shop clean it seems, the main priority is quality armor.",
   "bench" : "There is a simple wooden bench against the wall near the door on which customers may sit if they are waiting for a piece of armor to be properly refitted for them.",
   "windows" : "The windows on the north and south walls are usually kept open to allow some cool air into the stuffy room.",
   ]));
  set_exits(([
  "east":TCITY+"c75",
  ]));
}
void reset(){
  ::reset();
  if(!present("shamus",TO)){
  new(MON+"armorer2")->move(TO);
  }
}
