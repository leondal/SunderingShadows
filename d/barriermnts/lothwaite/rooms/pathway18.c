//pathway18.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_exits(([
      "northwest" : PATHEXIT"pathway16",
      "southeast" : PATHEXIT"pathway20",
   ]));
}
