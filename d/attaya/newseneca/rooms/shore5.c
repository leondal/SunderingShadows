//shore5.c - ~Circe~ 6/18/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"shore.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"beach8",
      "north" : ROOMS"beach9",
      "northeast" : ROOMS"beach10",
      "west" : ROOMS"shore4",
      "east" : ROOMS"shore6"
   ]));
}