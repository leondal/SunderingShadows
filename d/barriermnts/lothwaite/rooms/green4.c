//Village Green for Lothwaite.  Circe 9/18/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"green";

void create(){
   ::create();
   set_long( ::query_long()+"  Just to the west, a tall %^ORANGE%^"+
      "wooden pole %^GREEN%^stands against the sky.\n");
   set_exits(([
      "south" : PATHEXIT"green2",
      "west" : PATHEXIT"green3",
      "southwest" : PATHEXIT"green1"
   ]));
}