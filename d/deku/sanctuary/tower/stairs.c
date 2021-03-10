#include <std.h>
#include "../dragon.h";

inherit BTOWER;

void create() {
   ::create();
   set_long(
      "%^RESET%^This chamber is simple in its construction. A set of"+
      " stairways omniously rises up towards to a trap door in the"+
      " ceiling."
   );
   set_items( ([
      "stairs" : "These stone stairs are intricately cut and show wear, due to much use.",
   ]) );
   set_exits( ([
      "stairs" : TOWER+"lobby",
      "south" : TOWER+"prison15",
   ]) );
}

void reset() {
   ::reset();
   if(!present("apprentice")) {
      new(MON+"apprentice")->move(TO);
      new(MON+"apprentice")->move(TO);
   }
}
