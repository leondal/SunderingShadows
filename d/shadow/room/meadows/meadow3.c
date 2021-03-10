#include <std.h>
#include "meadow.h"
inherit MEADOW;

void create()
{
   ::create();
   set_long(""+TO->query_long()+" It looks like there's a pond to the north.");
   set("night long",""+TO->query("night long")+" There appears to be a"+
   " pond to the north.");
   set_exits(([
   "west" : ROOMS+"meadow4",
   "east" : ROOMS+"meadow2",
   "north" : ROOMS+"pond",
   "south" : ROOMS+"meadow8",
   ]));
}
