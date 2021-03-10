#include <std.h>
#include "../vale.h"
inherit SHORE_INH;

void create()
{
   ::create();
   set_exits(([
   "east" : ROOMS+"shore8",
   "west" : ROOMS+"shore10",
   "north" : ROOMS+"v69",
   "southwest" : ROOMS+"shore11",
   "southeast" : ROOMS+"shore7",
   ]));
}
