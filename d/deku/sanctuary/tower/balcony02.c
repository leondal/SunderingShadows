#include <std.h>
#include "../dragon.h";

inherit BBALCONY;

void create() {
   ::create();
   set_exits( ([
      "door" : TOWER+"study02",
      "northwest" : TOWER+"balcony01",
      "southwest" : TOWER+"balcony04",
   ]) );
   set_door("door",TOWER+"study02","door","tower key");
}
