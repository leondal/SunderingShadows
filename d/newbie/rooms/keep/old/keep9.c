#include <std.h>
#include "keep.h"
inherit ROOM;

void create()
{
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("light",1);
   set_short("Hallway of a Ruined Keep");
   set_long(
   "You are traveling down the hallway of a ruined keep. This inner section"+
   " seems to have taken less damage, the walls are almost fully intact"+
   " and the ceiling appears to be more stable here. %^GREEN%^Moss%^RESET%^"+
   " has still crept in from the entrance, growing along the edges of the"+
   " floor and walls. Mud has been tracked throughout the hallway by"+
   " someone or something. The hallway continues to the north, and just"+
   " ahead you can see a door on either side. To the south is the entrance"+
   " of the keep."
   );
   set_smell("default","The keep is filled with a damp, dank smell.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in better shape here. There are rarely any missing blocks and the"+
   " %^GREEN%^moss%^RESET%^ only grows in small sections.",
   "floor" : "The floor is made of stone bricks and is quite dirty. Mud has"+
   " been tracked through the hallway by something, but you can't tell what."+
   "%^GREEN%^Moss%^RESET%^ runs along the edges of the floor near the walls.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams seem a bit more sturdy here than on the outer edges of the keep.",
   "moss" : "%^GREEN%^Moss grows along sections of the walls and has reached"+
   " down to cover parts of the floor as well. It is green and looks rather"+
   " slimy, making footing treacherous in some places.",
   "mud" : "The mud almost totally covers the floor. The ceiling is in much"+
   " better shape here, so it must have been tracked in by something. There"+
   " is so much mud that you can't really make out any clear tracks, or"+
   " even tell how long ago something was here. It could've been months or"+
   " just a few hours.",
   ]));
   set_exits(([
   "south" : ROOMS+"keep1",
   "north" : ROOMS+"keep10",
   ]));
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
