//beach6.c - ~Circe~ 6/15/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"beach5",
      "north" : ROOMS"beach1",
      "northeast" : ROOMS"beach2",
      "east" : ROOMS"beach7",
      "southwest" : ROOMS"shore1",
      "south" : ROOMS"shore2",
      "southeast" : ROOMS"shore3"
   ]));
}