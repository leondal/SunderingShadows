#include "../example.h"

inherit STORAGE"street";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"street1"
   ]));
}
