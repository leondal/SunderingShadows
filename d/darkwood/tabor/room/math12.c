//updated by Circe 6/2/04 with color, etc.
#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",0);
   set_name("Mathowvy Road, Tabor");
   set_short("Mathowvy Road, Tabor");
   set_long(
   "%^BOLD%^Mathowvy Road, Tabor%^RESET%^\n"+
   "You are standing outside the fortress of %^YELLOW%^Caer Tabor "+
   "%^RESET%^now.  The road leads to a great %^BOLD%^%^BLACK%^iron "+
   "portcullis %^RESET%^that is the entrance to"+
   " the castle.  Large stone blocks carefully make up the walls of"+
   " the great fortress.  You can see archer slits in sections atop"+
   " the walls and can occasionally see a guard patrolling the top.\n\n"+
   "%^MAGENTA%^Mathowvy Road %^RESET%^continues to the southeast.\n"
   );
   set_listen("default","You hear the faint footsteps of the guards on patrol.");
   set_smell("default","The clean scent of the forest reaches the top of the hill.");
   set_items(([
   "town" : "You can see the buildings of the town south of here.",
   "castle" : "The great Caer Tabor looms before you, a portrait of"+
   " magnificence and defense.",
   "portcullis" : "There is a large iron portcullis with thick bars"+
   " and spikes that are driven into the ground when it is closed.",
   ]));
   set_exits(([
   "southeast" : ROOMDIR+"math11",
   "north" : ROOMDIR+"castle1",
   ]));
}

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

