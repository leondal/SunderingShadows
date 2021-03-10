#include <std.h>
#include "keep.h"
inherit VAULT;

void create()
{
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("light",2);
   set_short("Dead End of a Ruined Keep");
   set_long(
   "You are at the dead end of a hallway. The ceiling obviously collapsed on the"+
   " rest of the hallway to the south, making further passage impossible. %^GREEN%^Moss%^RESET%^"+
   " covers many of the broken blocks and extends to sections of the floor."+
   " There is a lot of mud here, probably from rain pouring in through the open"+
   " ceiling. On the east is a door that appears fairly sturdy."
   );
   set_smell("default","The keep is filled with dust.");
   set_listen("default","The wind wails against the outside walls.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in okay shape. There are a few cracks running through some blocks,"+
   " but they appear sturdy and mostly keep the wind out.",
   "floor" : "The floor is made of stone bricks and is covered in dirt and mud."+
   " There is a lot of mud here, most likely from rain water coming in through"+
   " the open ceiling and mixing with the dirt.",
   "ceiling" : "The ceiling directly above you is made of carefully squared stone"+
   " blocks that have been fitted together and are supported by beams in some"+
   " places. Just to the south the ceiling has completely caved in.",
   ({"beam","beams"}) : "The beams that support the ceiling seem sturdy enough.",
   "mud" : "The mud covers most of the floor here.",
   ({"dust","dirt"}) : "Dirt and dust cover the floor here.",
   "cobwebs" : "There are a couple cobwebs along the walls here.",
   "moss" : "%^GREEN%^Moss is covering most of the collapsed ceiling blocks and"+
   " has extended to nearby sections of the floor.%^RESET%^",
   ({"blocks","stone blocks","ceiling blocks"}) : "The blocks that once composed"+
   " the ceiling in the southern section of this hallway have all collapsed and"+
   " many have broken. They are now covered in %^GREEN%^moss%^RESET%^ and are"+
   " in pretty bad shape. You think you can see scorch marks on a few of the"+
   " blocks however, indicating that the collapse of the keep was not due to"+
   " an earthquake or some other natural disaster.",
   "door" : "The door here appears quite sturdy, despite the gaping hole in the"+
   " ceiling that is letting the worst of the elements in. It might even have"+
   " been repaired in a few places to cover gaps, but if that's the case the"+
   " person didn't do that good of a job and should have used better wood.",
   ]));
   set_exits(([
   "east" : ROOMS+"keep23",
   "north" : ROOMS+"keep21",
   ]));
   set_door("door",ROOMS+"keep23","east",0);
   set_string("door","open", "The door creaks open rather loudly.");
}
