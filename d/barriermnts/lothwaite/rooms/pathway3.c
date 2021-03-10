//pathway3.c - Path to Lothwaite.  Circe 1/9/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHPATH;

void create(){
   ::create();
   set_exits(([
      "north" : PATHEXIT"pathway2",
      "south" : PATHEXIT"pathway4"
   ]));
   slipping();
}
