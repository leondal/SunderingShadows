//pathway14.c - Path through Lothwaite.  Circe 5/10/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  The path continues here, leading "+
      "southwest toward the ramparts or northeast into the "+
      "village.  A smooth, grassy dip in the valley to the north "+
      "leads to two tall buildings.\n");
   set_exits(([
      "southwest" : PATHEXIT"pathway13",
      "northeast" : PATHEXIT"pathway15",
      "north" : PATHEXIT"grass1"
   ]));
}
