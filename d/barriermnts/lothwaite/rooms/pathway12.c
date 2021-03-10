//pathway12.c - Path through Lothwaite.  Circe 5/10/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  To the west, there seems to be an "+
      "iron-bound gate running through a tall earthen rampart.  The "+
      "path continues further northeast into the village.\n");
   set_exits(([
      "west" : PATHEXIT"pathway11",
      "northeast" : PATHEXIT"pathway13",
   ]));
}
