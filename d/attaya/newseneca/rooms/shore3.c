//shore3.c - ~Circe~ 6/18/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit STORAGE"shore.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"beach6",
      "north" : ROOMS"beach7",
      "northeast" : ROOMS"beach8",
      "west" : ROOMS"shore2",
      "east" : ROOMS"shore4"
   ]));
}