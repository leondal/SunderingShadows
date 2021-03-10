//riders object

#include <std.h>
inherit "/std/guild";


void create(){
	guild::create();
	set_name("riding boots");
	set_id(({"boots","Boots","Riding","riding","riding boots"}));
	set_short("%^BOLD%^%^BLUE%^pair of tall riding boots");
	set_long("%^BOLD%^%^BLUE%^"+
@OLI
	These are trully fine Riding boots.  They are made from black leather
and are so tall that they stop just under your knee.
OLI
	);
	set_ac(1);
   set_weight(5);
      set_limbs(({"right foot","left foot"}));
	set_value(1);
	set_guild_name("Rider");
	set_guild_items(({base_name(TO)}));
	set_leader("menolly");
   set_guild_hc(({"menolly","durin","isaac","rigel","cromack"}));
	set_type("clothing");
}

void init(){
    ::init();
    if(ETO == TP){
	if((string)TP->query_race() == "wemic"){
	    set_limbs(({"right forepaw","left forepaw"}));
	}
	TP->force_me("wear boots");
    }
}
