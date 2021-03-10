#include <std.h>
#include "/d/islands/argentrock/argabbr.h"
inherit ROOM;

void create() {
   ::create();
   set_name("Watcher Isle");
   set_short("Watcher Isle");
   set_terrain(BEACH);
   set_travel(FRESH_BLAZE);
   set_long("%^BOLD%^%^GREEN%^Watcher Isle%^RESET%^\n"
      "%^BOLD%^%^BLACK%^This is the rocky base of a tiny island "
      "just off the main coast of Argentrock. Waves crash about, "
      "and the dark sea surrounds the small landmass. The rocks "
      "on this mini island lead straight up to what appears to be "
      "a small ring of trees. The cliff face looks daunting and "
      "slick, but perhaps one could %^YELLOW%^<climb>%^BOLD%^%^BLACK%^ "
      "it. However, it might be safer to just %^YELLOW%^<swim>%^BOLD%^%^BLACK%^ back.\n%^RESET%^");
   set_climb_exits((["climb":({SHO+"island.c",20,roll_dice(10,8),100})]));
}
void init(){
   ::init();
   add_action("swimmy", "swim");
}

int swimmy() {
   if(!userp(TP)) return 1;
        if(TP->query_property("flying")) {
		  tell_room(ETP,TPQCN+" flies to the island.", TP);
          tell_object(TP,"%^ORANGE%^You decide not to swim"+
		  " to the island because flying is easier.");
		}
        else 
	 if(random(TP->query_internal_encumbrance()) > 
	             TP->query_skill("athletics")+100)
    {
        tell_object(TP,"%^BLUE%^You try to swim but sink quickly and disappear into the water!");
        tell_room(TO,"%^BLUE%^"+TPQCN+
		  " tries to swim but sinks quickly into the water and disappears!",TP);
        TP->do_damage(TP->return_target_limb(),roll_dice(1,2));
        TP->move("/d/islands/argentrock/inherit/sea");
        return 1;
    }
	tell_room(ETP,TPQCN+" swims to the island.", TP);
    tell_object(TP,"%^ORANGE%^It isn't easy but you fight the currents and swim to the island.");
    TP->move(SHO+"shore6");
     
   return 1;
}
