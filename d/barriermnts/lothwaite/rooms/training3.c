//training area for Lothwaite.  Circe 9/17/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"training";

void create(){
   ::create();
   set_long( ::query_long()+"  You are standing on the northern end of "+
      "the field.  Just to the north, there is a gate leading through "+
      "the wooden fence and out to a pathway, while the field opens "+
      "up to the south.\n");
   set_exits(([
      "east" : PATHEXIT"training4",
      "west" : PATHEXIT"training2",
      "southwest" : PATHEXIT"training5",
      "south" : PATHEXIT"training6",
      "southeast" : PATHEXIT"training7",
      "north" : PATHEXIT"training1"
   ]));
}