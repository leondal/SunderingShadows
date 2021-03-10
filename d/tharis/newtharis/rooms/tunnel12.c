#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"tunnel11",
      "south" : ROOMS"tunnel13",
   ]));
}

