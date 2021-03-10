//changed to use the common inherit general store list
//left the thieves tools (fixed it so they actually loaded)  *Styx* 9/3/01

#include <std.h>
inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
   set_property("no teleport",1);
   set_properties((["light":1, "indoors":1]));
 	set("short","A storage room for the general store.");
   set("long", "Supplies and such are stored here.\n");
   set_exits( (["up" : "/d/tharis/Tharis/general"]) );
}

void reset() {
   ::reset();
if(!present("rope 2") && !random(3))
   new("/d/common/obj/misc/rope")->move(TO);
if(!present("thief tools") && !random(2))
  new("/d/common/obj/misc/thief_tools.c")->move(TO);
}
