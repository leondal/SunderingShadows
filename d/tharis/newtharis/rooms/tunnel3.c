#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"tunnel2",
      "east" : ROOMS"tunnel4",
   ]));
}
