//pathway26.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit PATHEND;

void create(){
   ::create();
   set_long( ::query_long()+"  This seems to be the main pathway through the town.  "+
      "The path runs straight here for awhile, and what looks to be a shop of sorts "+
      "is just south of the path.  A shorter path going north leads to a larger building.\n");
   add_item("shop","A large wooden building much like the others of Lothwaite.  "+
      "The shutters are often open on the windows, and you can see various "+
      "items on shelves inside.");
   set_exits(([
      "west" : PATHEXIT"pathway25",
      "east" : PATHEXIT"pathway28",
      "north" : PATHEXIT"pathway27",
      "south" : PATHEXIT"general",
   ]));
   set_door("door",PATHEXIT"general","south",0);
   set_door_description("door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}