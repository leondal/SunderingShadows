#include <std.h>
#include "../githyanki.h"

inherit STORAGE"barracks.c";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"1_11",
      "south" : ROOMS"1_9",

    ]));   
}
