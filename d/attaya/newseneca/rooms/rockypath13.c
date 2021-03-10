//rockypath13.c - ~Circe~ 6/10/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit RPATH;

void create(){
   ::create();
   set_long(::query_long()+"The wall of %^ORANGE%^bedrock %^RESET%^"+
      "rises to the north here, blocking off most of the view of "+
      "the city.  All that is visible in that direction are the "+
      "towering %^BOLD%^co%^MAGENTA%^q%^WHITE%^ui"+
      "%^BLACK%^n%^WHITE%^a walls%^RESET%^ bordering the southern "+
      "edge of Seneca.  In all other directions, however, there is "+
      "a stunning view of the %^BOLD%^%^BLUE%^ocean%^RESET%^.  Here "+
      "the pathway leads to a carved%^ORANGE%^ stairway %^RESET%^"+
      "leading to the beach or upwards and west, leading to the "+
      "city.\n");
   set_exits(([
      "west" : ROOMS"rockypath12",
      "south" : ROOMS"beach3"
   ]));
}