#include <std.h>
#include "../githyanki.h"

inherit STORAGE"prison.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"1_33",
      "west" : ROOMS"1_19",
   ]));

}