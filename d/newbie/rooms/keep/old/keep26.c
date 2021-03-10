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
   set_short("Mess Hall of a Ruined Keep");
   set_long(
   "You are standing in the mess hall of a ruined keep. Everything around you is"+
   " pretty much in shambles. The ceiling to the east has completely caved in on the"+
   " rest of the mess hall, and most of the benches and tables have been destroyed."+
   " Plates and glasses are scattered about the room, with half-eaten meals on some."+
   " It's obvious that whatever happened here occurred rather suddenly and caught"+
   " people by surprise. The mud tracks are all over the room and also lead out the"+
   " door to the south, to the rest of the mess hall."
   );
   set_smell("default","The odor of spoiled food fills this room.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   "tables" : "The tables have mostly been smashed, either deliberately or by the"+
   " blocks of the eastern ceiling bouncing onto them. A few on the edges are still"+
   " intact but fairly rotted.",
   "benches" : "The benches have mostly been smashed along with the tables. A few"+
   " have completely rotted through, and others are mostly intact, usually near the"+
   " tables that are along the edges.",
   ({"plates","glasses"}) : "Several plates and glasses are scattered about the room,"+
   " most of them are broken. There are remains of half-eaten meals and patches of"+
   " mold from where drinks were long ago spilled.",
   "floor" : "The floor is covered in mud, dirt, mold, grime, and other things best"+
   " not thought of.",
   ({"wall","walls"}) : "Three of the walls here are in good shape, even though the"+
   " eastern ceiling collapsed. There are cracks and a few missing stones on the"+
   " north wall, but the other two are in pretty good shape given the circumstances.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep25",
   "south" : ROOMS+"keep28",
   ]));
}

void reset()
{
   ::reset();
   if(!present("xvart")) {
      switch(random(3)) {
         case 0:
            new(MONS+"xvart")->move(TO);
            break;
         case 1:
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            break;
         case 2:
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            break;
      }
   }
}
