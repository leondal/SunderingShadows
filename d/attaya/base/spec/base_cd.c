//Update to change some spawns, last update 10/4/98 - Octothorpe 1/6/10
#include <std.h>

inherit "/std/controld";

void create(){
   ::create();
   //set_max_level(46);
   set_monsters(({"/d/attaya/mon/archer.c","/d/attaya/mon/archer2.c","/d/attaya/mon/phalanx","/d/attaya/mon/guardian.c","/d/attaya/mon/warlock.c","/d/attaya/mon/nightstalker.c","/d/attaya/mon/poltergeist.c","/d/attaya/mon/uwarrior.c","/d/attaya/mon/toclhar.c","/d/islands/common/mon/necrophidius.c","/d/attaya/mon/solstice","/d/attaya/mon/entity"}),({30,40,30,45,20,35,50,45,25,25,32,40}));
}

