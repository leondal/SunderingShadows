#include <std.h>
#include "../tharis.h"
inherit STORAGE"shar_path";

void create(){
   ::create();
   set_exits(([
      "north" : MOUNTAIN"spath2",
      "southwest" : MOUNTAIN"spath4"
   ]));
}