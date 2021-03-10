#include <std.h>
#include "../githyanki.h"

inherit STORAGE"stables.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"2_62",
      "north" : ROOMS"2_56",
      "south" : ROOMS"2_58",
   ]));

}