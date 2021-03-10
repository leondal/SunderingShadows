#include <std.h>
#include "../dragon.h";

inherit BBALCONY;

void create() {
   ::create();
   set_exits( ([
      "northeast" : TOWER+"balcony02",
      "northwest" : TOWER+"balcony03",
      "upstairs" : TOWER+"hall01",
   ]) );
}
