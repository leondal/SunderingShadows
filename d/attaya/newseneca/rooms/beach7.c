//beach7.c - ~Circe~ 6/15/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"beach";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"beach6",
      "northwest" : ROOMS"beach1",
      "north" : ROOMS"beach2",
      "northeast" : ROOMS"beach3",
      "east" : ROOMS"beach8",
      "southwest" : ROOMS"shore2",
      "south" : ROOMS"shore3",
      "southeast" : ROOMS"shore4"
   ]));
}