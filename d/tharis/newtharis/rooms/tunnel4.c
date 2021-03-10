#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"tunnel3",
      "east" : ROOMS"tunnel6",
      "south" : ROOMS"tunnel5",
   ]));
}
