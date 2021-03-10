#include <std.h>
#include "../githyanki.h"

inherit STORAGE"3floor.c";

void create(){
   ::create();
   set_exits(([
      "southwest" : ROOMS"3_68",
      "southeast" : ROOMS"3_66",
   ]));

}