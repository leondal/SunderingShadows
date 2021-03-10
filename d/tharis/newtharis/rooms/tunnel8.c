#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"tunnel7",
      "east" : ROOMS"tunnel9",
   ]));
}