//path.c - path to Ekibi Caverns
//Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",1);
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
   set_name("A Narrow Footpath");
   set_short("A Narrow Footpath");
   set_long("This narrow footpath is lined with dirt scattered "+
      "across the stone surface.  It seems to have been worn "+
      "with many feet, though it now looks ill-used.  Occasional "+
      "pines dot the landscape around the path, rising up the "+
      "mountainside.  A small %^ORANGE%^hut %^RESET%^stands to the "+
      "southwest, while it looks like a %^BLUE%^cave %^RESET%^"+
      "opens up to the east.\n");
   set_listen("default","You hear the wind whistling through the pines.");
   set_smell("default","Fresh mountain air rises on the breeze.");
   set_items(([
      ({"path","dirt","footpath"}) : "The narrow footpath is "+
         "nothing more than a pathway that has been worn smooth "+
         "with all debris moved away over time.",
      ({"mountain","mountains","mountainside"}) : "Rising all "+
         "around this path are the steeper sides of mountains.  "+
         "The mountainside is dotted with pines, providing a little "+
         "shade.",
      ({"pines","pine trees","trees"}) : "The trees here are mostly "+
         "pine, and they allow very little undergrowth.",
      "hut" : "A small hut stands to the southwest beneath the pines.",
      "cave" : "A gaping cave entrance opens to the east."
   ]));
   set_exits(([
      "east" : PATHEXIT"cave",
      "southwest" : PATHEXIT"p2"
   ]));
}
