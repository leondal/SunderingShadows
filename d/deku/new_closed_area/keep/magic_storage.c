#include <std.h>
inherit "std/room";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short","A storage room for the magic shop.");
    set("long","Potions are stored here.  Mortals should NOT be here.");
   set_exits((["out":"/d/deku/keep/magic"]));
}

void reset() {
   ::reset();           
   if(!present("cure_poison")) {
      new("/d/common/obj/potion/cure_poison")->move(TO);
		new("/d/common/obj/potion/cure_poison")->move(TO);
		new("/d/common/obj/potion/cure_poison")->move(TO);
   }
}
