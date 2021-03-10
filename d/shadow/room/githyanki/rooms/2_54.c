#include <std.h>
#include "../githyanki.h"

inherit STORAGE"2floor.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"2_55",
      "south" : ROOMS"2_53",
      "down" : ROOMS"1_12",
   ]));

}