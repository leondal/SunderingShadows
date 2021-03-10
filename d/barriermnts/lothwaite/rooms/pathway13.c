//pathway13.c - Path through Lothwaite.  Circe 5/10/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  The path continues here, leading "+
      "southwest toward the ramparts or northeast into the "+
      "village.\n");
   set_exits(([
      "southwest" : PATHEXIT"pathway12",
      "northeast" : PATHEXIT"pathway14",
   ]));
}
