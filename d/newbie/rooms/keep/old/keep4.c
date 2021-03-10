#include <std.h>
#include "keep.h"
inherit VAULT;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("Hallway of a Ruined Keep");
   set_long(
   "You are traveling down the hallway of a ruined keep. There is a door"+
   " to the north here. It appears to have actually withstood the ravages"+
   " of time and decay better than most of the rest of this place. The"+
   " metal brackets holding it in place are a little rusty, and so is the"+
   " door knob, but it is still standing at least. The hallway continues"+
   " a little farther to the west, and it appears as though the roof has"+
   " caved in on that section. The hallway also extends back to the east"+
   " and the entrance of the keep."
   );
   set_smell("default","The keep is filled with a damp, dank smell.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   "door" : "The door to the north has managed to withstand the passage of"+
   " time with minimal decay. The metal brackets reinforcing the door as"+
   " well as the hinges and knob are quite rusty, but the door itself seems"+
   " sturdy enough.",
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in pretty bad shape. There are blocks missing in some places, others"+
   " are cracked, and %^GREEN%^moss%^RESET%^ is growing over large sections."+
   " They do nothing to stop the chill wind from reaching the inner part"+
   " of the keep now.",
   "floor" : "The floor is made of stone bricks and is quite dirty. Mud and"+
   " %^GREEN%^moss%^RESET%^ hide most of it and make it slipper to walk on.",
   "roof" : "The roof is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams have started to decay in some parts, and you don't get the"+
   " feeling that it is all too secure. One big earthquake might bring it"+
   " crashing down on your head.",
   "moss" : "%^GREEN%^Moss grows along most of the walls and has reached"+
   " down to cover parts of the floor as well. It is green and looks rather"+
   " slimy, making footing treacherous in some places.",
   "mud" : "The mud almost totally covers the floor. It's probably a mixture"+
   " of the settled dust with the water that appears to have leaked in"+
   " from the roof that is in rather bad shape.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep5",
   "east" : ROOMS+"keep3",
   "north" : ROOMS+"keep6",
   ]));
   set_door("door",ROOMS+"keep6","north","keep master_key");
   set_locked("door",1,"lock");
   lock_difficulty("door",40,"lock");
   set_string("door","open","The door creaks open rather loudly.");
   set_string("door","close","The hinges on the door creak noisily as it closes.");
}

void reset()
{
   ::reset();
   if(!random(3)) return;
   if(!present("spider") && !present("rat")) {
      switch(random(15)) {
         case 0..7:
            new(MONS+"spider")->move(TO);
            break;
         case 8..10:
            new(MONS+"rat")->move(TO);
            break;
         case 11..13:
            new(MONS+"rat")->move(TO);
            new(MONS+"rat")->move(TO);
            break;
         case 14:
            new(MONS+"rat")->move(TO);
            new(MONS+"rat")->move(TO);
            new(MONS+"rat")->move(TO);
            break;
      }
   }
}
