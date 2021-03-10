//Village Green for Lothwaite.  Circe 9/18/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"green";

void create(){
   ::create();
   set_long( ::query_long()+"  Just to the northwest, a tall %^ORANGE%^"+
      "wooden pole %^GREEN%^stands against the sky.\n");
   set_exits(([
      "south" : PATHEXIT"pathway25",
      "north" : PATHEXIT"green4",
      "west" : PATHEXIT"green1",
      "northwest" : PATHEXIT"green3"
   ]));
}