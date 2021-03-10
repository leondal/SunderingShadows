#include <std.h>
#include "../githyanki.h"

inherit STORAGE"3floor.c";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"3_67",
      "southwest" : ROOMS"3_65",
   ]));

}