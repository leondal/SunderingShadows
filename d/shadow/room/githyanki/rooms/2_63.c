#include <std.h>
#include "../githyanki.h"

inherit STORAGE"stables.c";

void create(){
   ::create();
   set_exits(([
      "west" : ROOMS"2_56",
      "south" : ROOMS"2_62",
   ]));

}

void pick_critters(){
    set_monsters(({MOBS"gith_captain"}),({1}));
       
}