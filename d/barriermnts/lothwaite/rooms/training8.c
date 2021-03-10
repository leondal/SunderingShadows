//training area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"training";

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing in the southwestern "+
      "corner of the training field.  The field opens up to the "+
      "northeast.\n");
   set_exits(([
      "northeast" : PATHEXIT"training6",
      "north" : PATHEXIT"training5",
      "east" : PATHEXIT"training9"
   ]));
}
