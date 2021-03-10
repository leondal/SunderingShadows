#include <std.h>
#include "../githyanki.h"

inherit STORAGE"prison.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"1_17",
      "up" : ROOMS"2_54",
   ]));

}