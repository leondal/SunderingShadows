#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"tunnel10",
      "south" : ROOMS"tunnel12",
   ]));
}

