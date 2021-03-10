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
   set_short("Hallway of a Ruined Keep");
   set_long(
   "You are traveling down the hallway of a ruined keep. As you move further within,"+
   " it seems to be in better shape. There are no holes or even cracks in the walls"+
   " here, and no moss growing anywhere. You do see a few cobwebs in places, and"+
   " lots of dust and mud. The hallway continues to the north where you can see it"+
   " splits off to the east and west shortly ahead. Directly south of here are two"+
   " doors on either side of the hallway, with the entrance to the keep further"+
   " south." 
   );
   set_smell("default","The keep is filled with dust.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in much better shape here. There are no missing blocks or even cracks.",
   "floor" : "The floor is made of stone bricks and is covered in dirt and mud. The"+
   " mud has been tracked through the hallway by something, but you can't tell what.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams seem fairly stable.",
   "mud" : "The mud almost totally covers the floor. The ceiling is in much"+
   " better shape here, so it must have been tracked in by something. There"+
   " is so much mud that you can't really make out any clear tracks, or"+
   " even tell how long ago something was here. It could've been months or"+
   " just a few hours.",
   ({"dust","dirt"}) : "Dirt and dust cover the floor here.",
   "cobwebs" : "There are a few cobwebs in places along the walls.",
   ]));
   set_exits(([
   "south" : ROOMS+"keep10",
   "north" : ROOMS+"keep13",
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
