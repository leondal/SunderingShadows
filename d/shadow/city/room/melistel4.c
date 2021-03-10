//Octothorpe (1/4/12)
//Shadow, Melistel Avenue 4

#include <std.h>
#include "../defs.h"
inherit INH+"melistel";

void create(){
   ::create();
   set_exits(([
      "north" : ROOMS"northcross",
      "south" : ROOMS"melistel3",
      "west" : "/d/player_stores/poffices/shadow",
   ]));   
}
