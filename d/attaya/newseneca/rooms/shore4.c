//shore4.c - ~Circe~ 6/18/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"shore.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"beach7",
      "north" : ROOMS"beach8",
      "northeast" : ROOMS"beach9",
      "west" : ROOMS"shore3",
      "east" : ROOMS"shore5"
   ]));
}