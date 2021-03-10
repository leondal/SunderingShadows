//skyline43
#include <std.h>
#include "../seneca.h"

inherit SKYLINE;

void create(){
   ::create();
   set_long(::query_long()+"To both the east and west lie %^GREEN%^"+
      "gardens %^RESET%^with monuments set among stone benches.  "+
      "North of here is the wide %^BOLD%^town square %^RESET%^"+
      "at the juncture of two major roadways.\n");
   set_exits(([
      "west" : ROOMS"monument4",
      "east" : ROOMS"monument3",
      "north" : ROOMS"square",
      "south" : ROOMS"skyline45"
   ]));
}
