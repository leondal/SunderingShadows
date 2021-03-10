#include <std.h>
#include "../githyanki.h"

inherit STORAGE"2floor.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"2_59",
      "north" : ROOMS"2_53",
   ]));

}