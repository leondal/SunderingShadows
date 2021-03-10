#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_short("Storage room upon the tree");
   set_long("%^GREEN%^Storage room upon the tree%^RESET%^
The room is quite dark because the windows are all closed. It consists of "
      "numerous wooden racks. The racks are full of weapons. Occasionally "
      "you see a rat rear its head out of the hole at the wall, smelling "
      "for food. An archway leads out of the storage to the east.");
   set_items( (["windows":"They are closed and seems you cannot open it.",
      "racks":"Some wooden racks.",
      "weapons":"These are weapons used by people during their battles.",
      "rat":"Where is it now? It must be hungry.",
      "archway":"It leads out to the corridor.",
      "wall":"The wall is wooden also, like the rest of the house.",
      "hole":"A small hole at the wall near one of the racks."]) );
   set_smell("default","Rusty metal is the only thing you can smell here.");
   set_listen("default","A rat makes some noises.");
   set_search( "hole", (: TO,"search_hole" :) );
   set_exits( (["east":RPATH1+"1three14",
      "south":RPATH1+"1three18"]) );
}

void search_hole() {
   write("There you are dirty rat!");
   new(MPATH+"rat")->move(TO);
}
