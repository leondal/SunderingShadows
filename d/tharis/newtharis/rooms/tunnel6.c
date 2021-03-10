#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"tunnel5",
      "north" : ROOMS"tunnel7",
   ]));
}
