
#include <std.h>

inherit "/std/controld";

void create(){
   ::create();
   set_monsters(({"/d/attaya/mon/archer.c","/d/attaya/mon/archer2.c","/d/attaya/mon/phalanx","/d/attaya/mon/guardian.c","/d/islands/common/mon/scorpion.c","/d/attaya/mon/nightstalker.c","/d/attaya/mon/poltergeist.c","/d/attaya/mon/uwarrior.c","/d/attaya/mon/toclhar.c","/d/islands/common/mon/necrophidius.c","/d/attaya/mon/solstice"}),({40,40,20,35,25,35,50,35,35,15,10}));
}
