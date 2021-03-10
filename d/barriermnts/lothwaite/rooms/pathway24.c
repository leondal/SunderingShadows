//pathway24.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit PATHEND;

void create(){
   ::create();
   set_long( ::query_long()+"  This seems to be the main pathway through the town.  "+
      "The path runs straight here for awhile, and what looks to be a shop of sorts "+
      "is just south of the path.  The village green opens up to the north.\n");
   add_item("shop","A large wooden building much like the others of Lothwaite.  "+
      "Unlike the others, however, this building has %^CYAN%^windows %^RESET%^"+
      "fitted with class that display a large selection of jewelry.");
   add_item(({"green","village green"}),"The village green to the north "+
      "is a large open area where outdoor festivals are held.  In the "+
      "northwestern corner, you can make out what looks to be a pole, "+
      "but otherwise, the green is open.");
   set_exits(([
      "west" : PATHEXIT"pathway23",
      "east" : PATHEXIT"pathway25",
      "south" : PATHEXIT"jeweler",
      "north" : PATHEXIT"green1",
   ]));
   set_door("door",PATHEXIT"jeweler","south",0);
   set_door_description("door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}
