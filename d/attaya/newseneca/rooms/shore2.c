//shore2.c - ~Circe~ 6/18/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"shore.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"beach5",
      "north" : ROOMS"beach6",
      "northeast" : ROOMS"beach7",
      "west" : ROOMS"shore1",
      "east" : ROOMS"shore3"
   ]));
}