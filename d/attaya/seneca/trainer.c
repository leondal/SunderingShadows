//trainer.c
#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("The training arena in Seneca");
   set_long(
@DESC
You are in %^CYAN%^Vaistus' Training Arena%^RESET%^. The building appears
to have once been a warehouse and has now been divided
into various training areas. There are racks along the 
walls filled with all types of weapons. The sounds of battle
fill the room, as Vaistus is constantly dueling with all
who come, keeping his skills sharp.
DESC
   );
   set_light(2);
   set_indoors(1);
   set_exits(([
      "east":"/d/attaya/seneca/street11"
   ]));
}


void reset() {
   ::reset();
   if(!present("vaistus")) {
      new("/d/attaya/seneca/mon/vaistus")->move(TO);
   }
}
