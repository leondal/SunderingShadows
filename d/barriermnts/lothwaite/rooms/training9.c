//training area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"training";

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing along the southern "+
      "edge of the training field.  The field opens up to the "+
      "north.\n");
   set_exits(([
      "northwest" : PATHEXIT"training5",
      "north" : PATHEXIT"training6",
      "northeast" : PATHEXIT"training7",
      "east" : PATHEXIT"training10",
      "west" : PATHEXIT"training8"
   ]));
}
