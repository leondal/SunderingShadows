#include <std.h>
#include "../githyanki.h"

inherit STORAGE"3floor.c";

void create(){
   ::create();
   set_exits(([
      "northeast" : ROOMS"3_66",
      "south" : ROOMS"3_64",
   ]));

}