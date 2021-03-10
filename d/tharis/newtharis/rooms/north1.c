#include <std.h>
#include "../tharis.h"
inherit STORAGE"trade";

void create(){
   ::create();
   set_long(::query_long()+" Directly west lies a small stone building, while east sits an even "
"less impressive building, barely more than a shack. It looks distinctly out of place among the "
"better-maintained structures of this street.%^RESET%^\n");
   set_exits(([
      "west" : ROOMS"portal",
      "east" : ROOMS"tharis_crystals",
      "south" : ROOMS"north2",
      "north" : ROOMS"ngate1",
   ]));
}