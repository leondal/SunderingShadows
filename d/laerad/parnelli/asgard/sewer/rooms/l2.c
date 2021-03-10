#include <std.h>
#include "../lizard.h"
inherit ROOM;
void create(){
// object ob;  removing boards except IC/town type boards *Styx*  6/18/03
::create();
set("short","Damp muddy cavern.");
set("long","You find yourself in a large cavern.  Mud sticks to you and chills your exposed skin.  "+
   "The festering smell of the material washed into this room with you hangs thick in the air.  "+
   "Stalagmites sprout from the floor and look much like the teeth of a large beast.  "+
   "Stalactites dangle from the ceiling and glisten with a fine coat of water.  "+
   "The ceiling is high above you somewhere in the darkness.  "+
   "Loose rocks from fallen stalactites litter the floor and the cavern opens up to the south.");
set_property("indoors",1);
set_property("no teleport",1);
set_property("light",1);
set_terrain(NAT_CAVE);
set_travel(DIRT_ROAD);
set_smell("default","The smell of the sewer water dominates the area.");
set_listen("default","An occasional drop from a stalactite splashes to the floor.");
set_items(([
   "walls":"Much like what you would expect cave walls to be like, hard, wet and cool to the touch.",
   "floor":"Littered with rubble from broken stalactites watching your step and	watching your head may prove interesting.",
   ({"stalactite","stalactites"}):"Hanging high above your head...sure hope they do not crash down upon you.",
   ({"stalagmites","stalagmite"}):"Sprouting from the floor these stones vary in size and could be hiding many things from your vision."
   ]));
set_exits(([
   "south":LROOMS+"l6",
   "southeast":LROOMS+"l7"
 ]));
/*
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "slate board", "cavern board" }) );
  ob->set_board_id("cavern_board");
  ob->set("short", "%^GREEN%^Sewer Cavern Board%^RESET%^");
 ob->set("long", "%^GREEN%^This is a slate board where the adventurers "
          "who pass through this cavern scratch information about their travels in this area.  "
          "There is a warning in smallprint about not giving away secrets and ruining it for others.%^RESET%^\n");
  ob->set_max_posts(30);
  ob->set_location("/d/laerad/parnelli/asgard/sewer/rooms/l2");
*/
}
