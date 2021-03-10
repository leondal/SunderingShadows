#include <std.h>
#include "keep.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("Dead End of a Ruined Keep");
   set_long(
   "You have come to the end of the hallway, for the roof has caved in"+
   " just ahead of you and collapsed the passage. Many heavy stones have"+
   " piled here and there are far too many to attempt to move. Water has"+
   " come in from when it rains and %^GREEN%^moss%^RESET%^ cover most of the walls and"+
   " floor, making the footing treacherous."
   );
   set_smell("default","The dank scent of moss fills the air.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in pretty bad shape. There are blocks missing in some places, others"+
   " are cracked, and %^GREEN%^moss%^RESET%^ is growing over large sections."+
   " They do nothing to stop the chill wind from reaching the inner part"+
   " of the keep now.",
   "floor" : "The floor is made of stone bricks and is quite dirty. Mud and"+
   " %^GREEN%^moss%^RESET%^ hide most of it and make it slippery to walk on.",
   "roof" : "The roof has caved in just ahead, completely blocking the hallway.",
   "moss" : "%^GREEN%^Moss grows along most of the walls and all of the"+
   " floor thanks to the open roof. It is green and looks rather"+
   " slimy, making footing treacherous here.",
   "mud" : "The mud almost totally covers the floor. It's probably a mixture"+
   " of the settled dust with the water that appears to have poured in"+
   " from the large opening in the ceiling.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep7",
   ]));
}

void reset()
{
   ::reset();
   if(!random(2)) return;
   if(!present("spider") && !present("rat")) {
      switch(random(15)) {
         case 0..4:
            new(MONS+"spider")->move(TO);
            break;
         case 5..7:
            new(MONS+"spider")->move(TO);
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
