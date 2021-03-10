//beach2.c - ~Circe~ 6/15/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"beach1",
      "east" : ROOMS"beach3",
      "southwest" : ROOMS"beach6",
      "south" : ROOMS"beach7",
      "southeast" : ROOMS"beach8"
   ]));
}