//fallen angels object

#include <std.h>
inherit "/std/guild";



void create(){
	guild::create();
	set_name("Leather belt");
	set_id(({"belt","Belt","leather belt","Leather belt","Leather Belt"}));
	set_short("Black leather belt");
	set_long(
	"This belt is made from a fine black leather.  Small pouches "+
	"hang from its sides and a beautiful buckle in the shape of "+
	"an Angel is attached to the front.  The insignia of the Fallen "+
	"Angels is carved into the buckle as well."
	);
	set_weight(5);
	set_ac(1);
	set_limbs(({"waist"}));
	set_value(0);
	set_guild_name("Fallen Angel");
	set_guild_items(({base_name(TO)}));
	set_leader("jinglefoot");
	set_guild_hc(({
		"jinglefoot",
		"rikus",
		"zero"
	}));
	set_type("clothing");
}

void init(){
	::init();
	
	if(ETO == TP){
		TP->force_me("wear belt");
		tell_object(TP,"As you wear the belt you feel a confidence you never knew you posessed.");
	}
}
