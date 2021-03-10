#include <std.h>
#include "../tharis.h"
inherit STORAGE"wall";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"wall26",
      "west" : ROOMS"wall28",
      "down" : SEWERS"sewer15",
   ]));
   set_invis_exits(({"down"}));

}

void reset(){
    ::reset();
    if(!present("beggar")) new(MOBS"os_beggar.c")->move(TO); 
}
