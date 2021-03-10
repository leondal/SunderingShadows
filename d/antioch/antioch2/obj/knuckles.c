#include <std.h>
#include "../antioch.h"
inherit "/d/common/obj/weapon/claw.c";

// int twoHanded;  not used so getting rid of it *Styx*  12/24/03

void create()
{
	::create();
	set_name("knuckles");
	set_short("Brass knuckles");
	set_id(({"knuckles","brass kunckles","set of knuckles"}));
	set_long(
	"This is a set of brass knuckles that are worn on the fingers of your hand. "+
	" They consist of metal loops that you put your fingers through and have sharp"+
	" spikes on the other side that you use to hit your opponent with."
	);
/*	set_weight(6);
	set_wc(1,4);
	set_large_wc(1,3);
	set_type("piercing");
	set_size(1);*/
	set_wield((:TO,"wieldme":));
	set_unwield("You carefully remove the brass knuckles.");
	set_value(10);
//	set_prof_type("knuckles");
}

int wieldme()
{
	if((int)ETO->query_size() > 2) {
		tell_object(ETO,"These knuckles are too small for your big hands.");
		return 0;
	}
	if((int)ETO->query_size() < 2) {
		tell_object(ETO,"These knuckles are too large for your hands!");
		return 0;
	}
	tell_object(ETO,"You slip the knuckles over your fingers.");
	tell_room(environment(ETO),""+ETO->query_cap_name()+" slips the knuckles over"+
	" "+ETO->query_possessive()+" fingers.",ETO);
	return 1;
}
