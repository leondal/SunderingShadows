#include <std.h>
#include "../githyanki.h"

inherit STORAGE"stables.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"2_61",
      "north" : ROOMS"2_57",
   ]));

}