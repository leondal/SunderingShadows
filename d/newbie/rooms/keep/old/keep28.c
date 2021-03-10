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
   "You are standing in the mess hall of a ruined keep. This section of the mess hall"+
   " is less damaged than the first part. Only a couple of the benches and tables"+
   " have been destroyed. It also appears that this section has been used by somebody,"+
   " there are several plates with the remains of relatively recent meals on them"+
   " still. The meals don't look too appetizing, and there are no utensils with which"+
   " to eat them, so you get the impression that it is not a civilized group that has"+
   " taken residence in these ruined halls. The mud tracks lead north and east."
   );
   set_smell("default","The odor of spoiled food fills this room.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   "tables" : "The tables are mostly intact here and have plates with some more"+
   " recent meals scattered on the tops of a few of them.",
   "benches" : "The benches are mostly intact, although they are covered in dirt"+
   " and grime. Whoever has been using this place is definitely not the clean type.",
   "plates" : "Several plates with more recent meals are scattered about"+
   " the tables. The meals don't look very good, they are barely cooked and sometimes"+
   " molded, but they are probably only days or weeks old.",
   "floor" : "The floor is covered in mud, dirt, mold, grime, and other things best"+
   " not thought of.",
   ({"wall","walls"}) : "The walls are in fairly good shape, all things considered.",
   ]));
   set_exits(([
   "east" : ROOMS+"keep29",
   "north" : ROOMS+"keep26",
   ]));
}

void reset()
{
   ::reset();
   if(!present("xvart") && !random(3)) {
      switch(random(3)) {
         case 0:
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            break;
         case 1:
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            break;
         case 2:
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            new(MONS+"xvart")->move(TO);
            break;
      }
   }
}
