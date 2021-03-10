#include <std.h>
#include "../githyanki.h"

inherit STORAGE"2floor.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"2_54",
   ]));

}