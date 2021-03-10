//training area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"training";

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing along the eastern "+
      "edge of the field beside the fence.  On the other side of the "+
      "fence, the chapel stands against the sky.\n");
   set_exits(([
      "northwest" : PATHEXIT"training3",
      "north" : PATHEXIT"training4",
      "south" : PATHEXIT"training10",
      "southwest" : PATHEXIT"training9",
      "west" : PATHEXIT"training6"
   ]));
}
