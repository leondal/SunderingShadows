#include <std.h>
#include "../tharis.h"
inherit STORAGE"shar_path";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^%^CYAN%^Just ahead, this path meets "+
      "a wide road.\n");
   set_exits(([
      "north" : "/d/tharis/road/eroad4",
      "southwest" : MOUNTAIN"spath2"
   ]));
}