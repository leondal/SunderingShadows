//training area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"training";

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing at the northeastern "+
      "corner of the field.  A gate leading through the fence is to "+
      "the west, while the field opens up to the southwest.\n");
   set_exits(([
      "west" : PATHEXIT"training3",
      "southwest" : PATHEXIT"training6",
      "south" : PATHEXIT"training7"
   ]));
}