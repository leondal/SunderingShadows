//training area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"training";

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing in the southeastern "+
      "corner of the training field.  The field opens up to the "+
      "northwest.\n");
   set_exits(([
      "northwest" : PATHEXIT"training6",
      "north" : PATHEXIT"training7",
      "west" : PATHEXIT"training9"
   ]));
}
