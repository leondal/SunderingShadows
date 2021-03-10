#include "../kildare.h"

inherit HIDDENTUNNEL;

void create(){
   ::create();
   set_long(::query_long()+"\nTo the northeast, you see a wider, "+
      "somewhat more traveled tunnel.  It looks as if this narrow "+
      "tunnel continues on to the west, winding deeper down into the "+
      "mountain.\n");
   set_exits(([
      "west" : ROOMS"hiddentunnel2",
      "northeast" : ROOMS"tunnel5"
   ]));
}