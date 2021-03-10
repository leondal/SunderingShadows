#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"tunnel9",
      "south" : ROOMS"tunnel11",
   ]));
}

