//pathway2.c - Path to Lothwaite.  Circe 1/9/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHPATH;

void create(){
   ::create();
   set_exits(([
      "northwest" : PATHEXIT"pathway1",
      "south" : PATHEXIT"pathway3"
   ]));
   slipping();
}
