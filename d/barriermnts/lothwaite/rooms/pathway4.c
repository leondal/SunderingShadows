//pathway4.c - Path to Lothwaite.  Circe 1/9/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHPATH;

void create(){
   ::create();
   set_exits(([
      "north" : PATHEXIT"pathway3",
      "south" : PATHEXIT"pathway5"
   ]));
   slipping();
}
