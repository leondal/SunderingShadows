#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

void create(){
   ::create();
   set_long(::query_long()+" The tunnel comes to an abrupt end here.%^RESET%^\n");
   set_exits(([
      "north" : SEWERS"sewer1",
      "up" : ROOMS"tunnel9",
   ]));
   set_invis_exits(({"up"}));
   set_search("default","Searching around this dead end, you realise that some of the bricks on the back wall are unevenly placed.");
   set_search("bricks","Following the few uneven bricks towards the ceiling, you realise that there is a hidden opening concealed within the shadows above.");
   set_pre_exit_functions(({"up"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"%^BLUE%^You end up with slimy hands as you climb your way up the wall and into a dimly-lit tunnel above.%^RESET%^");
   tell_room(TO,"%^BLUE%^"+TPQCN+" climbs up the uneven back wall and disappears into the shadows above.%^RESET%^",TP);
   return 1;
}