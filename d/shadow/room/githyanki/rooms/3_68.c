#include <std.h>
#include "../githyanki.h"

inherit STORAGE"3floor.c";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"3_69",
      "northeast" : ROOMS"3_67",
   ]));

}