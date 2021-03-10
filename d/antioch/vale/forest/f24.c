#include <std.h>
#include "../vale.h"
inherit FOREST;

void create()
{
   ::create();
   set_exits(([
   "south" : FPATH+"f23",
   "west" : FPATH+"f25",
   "southwest" : "/d/antioch/vale/forest/aash_trail14",
   ]));
}
