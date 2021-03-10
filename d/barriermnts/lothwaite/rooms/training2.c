//training area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"training";

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing at the northwestern "+
      "corner of the field now, just south of the smithy.  You can "+
      "make out the forge a little further northwest.\n");
   set_exits(([
      "east" : PATHEXIT"training3",
      "south" : PATHEXIT"training5",
      "southeast" : PATHEXIT"training6"
   ]));
}