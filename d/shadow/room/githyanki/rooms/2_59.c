#include <std.h>
#include "../githyanki.h"

inherit STORAGE"2floor.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"2_60",
      "west" : ROOMS"2_52",
   ]));

}