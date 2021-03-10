#include <std.h>
#include "../antioch.h"
//Updates made for armour feat conversion Octothorpe 5/11/09
inherit "/d/common/obj/armour/breastplate.c";

void create()
{
	::create();
	set_name("breastplate");
	set_short("A shiny breastplate");
	set_id(({"breastplate","breast plate","shiny breast plate","shiny breastplate"}));
	set_long(
	"This suit of metal armor has been carefully crafted together by an expert smith. "+
	" It covers the torso, leaving the arms free to attack, but also allowing more"+
	" flexibility of movement than other similar armors. "
	);
        //set_type("armor");
        //set_limbs(({"torso"}));
        //set_weight(35);
        //set_ac(4);
        //set_value(1000);
	set_wear((:TO,"wearme":));
}

void init()
{
	::init();
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!living(ETO)) return;
	if(!interactive(ETO)) return;
	if(ETO->is_class("ranger") && !query_worn()) {
		set_type("leather");
	}
	else if(query_worn()) return;
	else {
                //set_type("armor");
	}
}


int wearme()
{
	if(TP->is_class("ranger")) {
		set_type("leather");
		return 1;
	}
	else {
                //set_type("armor");
		return 1;
	}
}
