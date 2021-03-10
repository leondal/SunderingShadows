#include <std.h>
#include "../githyanki.h"

inherit STORAGE"barracks.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"1_37",
      "west" : ROOMS"1_23",

    ]));   
}
