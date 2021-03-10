//training area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"training";

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing along the western "+
      "edge of the field beside the fence.\n");
   set_exits(([
      "north" : PATHEXIT"training2",
      "northeast" : PATHEXIT"training3",
      "east" : PATHEXIT"training6",
      "southeast" : PATHEXIT"training9",
      "south" : PATHEXIT"training8"
   ]));
}