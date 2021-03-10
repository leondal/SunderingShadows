#include <std.h>
#include "../githyanki.h"

inherit STORAGE"3floor.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"3_65",
   ]));

}