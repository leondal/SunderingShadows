#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"tunnel6",
      "north" : ROOMS"tunnel8",
   ]));
}
