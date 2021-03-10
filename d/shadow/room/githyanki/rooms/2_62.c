#include <std.h>
#include "../githyanki.h"

inherit STORAGE"stables.c";

void create(){
   ::create();
   set_exits(([
      "south" : ROOMS"2_61",
      "west" : ROOMS"2_57",
      "north" : ROOMS"2_63",
   ]));

}