#include <std.h>
#include "../dragon.h";

inherit BBALCONY;

void create() {
   ::create();
   set_exits( ([
      "door" : TOWER+"study03",
      "northeast" : TOWER+"balcony01",
      "southeast" : TOWER+"balcony04",
   ]) );
   set_door("door",TOWER+"study03","door","tower key");
}
