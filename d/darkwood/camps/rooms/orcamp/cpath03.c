#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "east" : CPATH+"cpath04",
      "southwest" : CPATH+"cpath02",
   ]) );
   set_listen("default","%^RESET%^%^CYAN%^There is a slight noise coming from the surrounding forest.%^RESET%^");
   set_trap_functions(({"southwest"}),({"jump_em"}),({"southwest"}));
   set_search("default","The bushes seem odd.");
   set_search("bushes","There appears to be something waiting in the bushes to the southwest.");
}


int jump_em() {
object ob;
toggle_trap("southwest");
   if(interactive(TP)){
   tell_object(TP,"%^BOLD%^%^RED%^As you turn to leave, two orcs ambush you!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^RED%^As "+TPQCN+" turns to leave, two orcs jump out!%^RESET%^",TP);
   ob = new(MON+"raider");
   ob->set_property("no bows",1);
   ob->move(TO);
   ob->force_me("block east");
   ob = new(MON+"banditt");
   ob->set_property("no bows",1);
   ob->move(TO);
   ob->force_me("block southwest");
   return 1;
}
}
