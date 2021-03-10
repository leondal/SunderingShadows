#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("Kaarell's Laboratory");
   set_long("%^GREEN%^Kaarell's Laboratory%^RESET%^\n"+
   "The pungent odor of chemicals and a sense of %^RED%^arcane magic%^RESET%^"+
   " overwhelm you as you enter this room.  You notice a number of grey"+
   " stone tables and benches on which sit numerous vials and potions,"+
   " some steaming away, plus a variety of scrolls with exquisite, but"+
   " illegible, writing on them. While the walls and floor are still made"+
   " from the branches of the %^BOLD%^%^GREEN%^living oak%^RESET%^, there"+
   " seems to be a magical force in place protecting them from any of the"+
   " mishaps and explosions that mages young and old are renowned for,"+
   " since you notice no damage to the actual tree. Looking to the far"+
   " wall, you notice your reflection in a crystal clear mirror, mounted"+
   " within a frame of magical %^YELLOW%^golden wood%^RESET%^.");
   set_smell("default","Your senses are assaulted by the pungent odor"+
   " of chemicals and arcane components.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_door("door",RPATH3+"3two19","north","kaarells_key");
   set_exits( (["north":RPATH3+"3two19"]) );
}
