#include <std.h>
#include "../githyanki.h"

inherit STORAGE"3floor.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"3_73",
      "east" : ROOMS"3_72",
      "south" : ROOMS"3_70",
   ]));

}