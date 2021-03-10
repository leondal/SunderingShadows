//shore6.c - ~Circe~ 6/18/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"shore.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"beach9",
      "north" : ROOMS"beach10",
      "northeast" : ROOMS"beach11",
      "west" : ROOMS"shore5",
      "east" : ROOMS"shore7"
   ]));
}