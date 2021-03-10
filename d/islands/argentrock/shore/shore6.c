#include <std.h>
#include "../argabbr.h"
inherit INH+"shore";

void create() {
    ::create();
    set_name("Argentrock Shore");
    set_short("Argentrock Shore");
    set_terrain(BEACH);
    set_travel(FRESH_BLAZE);
    set_long(::query_long()+"
%^BOLD%^%^BLACK%^It look like there is a small %^ORANGE%^island%^BLACK%^ further out to sea.%^RESET%^");
    set_items( ([ 
                    ({"rocks","shore"}):"The rocks are black and slick from sea water.",
                    ({"sea"}):"The sea looks dark and mysterious.",
                    ({"forest"}):"The thick forest looms above.",
                    ({"island"}):"The island looks to be a "+
                    "large rocky outcropping with trees on top. Perhaps you could <swim> there.",
                    ]) );
    set_exits( (["northwest":SHO+"shore5",
                 "south":SHO+"shore7"]) );
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
    TP->move(SHO+"island1");
     
   return 1;
}

