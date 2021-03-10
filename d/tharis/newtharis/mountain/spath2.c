#include <std.h>
#include "../tharis.h"
inherit STORAGE"shar_path";

void create(){
   ::create();
   set_exits(([
      "northeast" : MOUNTAIN"spath1",
      "south" : MOUNTAIN"spath3"
   ]));
}