#include <std.h>
#include "../dragon.h";

inherit BBALCONY;

void create() {
   ::create();
   set_exits( ([
      "door" : TOWER+"study01",
      "southeast" : TOWER+"balcony02",
      "southwest" : TOWER+"balcony03",
      "downstairs" : TOWER+"lobby",
   ]) );
   set_door("door",TOWER+"study01","door","tower key");
}

void reset() {
   ::reset();
   if(!present("animated guard")) {
      new(MON+"guard")->move(TO);
      new(MON+"guard")->move(TO);
   }
}
