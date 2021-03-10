#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("bodice");
	set_short("%^RESET%^%^ORANGE%^A leather bodice%^RESET%^");
	set_id(({"bodice","leather bodice","brown bodice","brown leather bodice"}));
	set_long(
	"%^ORANGE%^This is a tight fitting leather bodice.  It helps to keep a girl's figure"+
	" looking slim and trim, tightly lacing up the front.  The outside is"+
	" made of slightly hardened leather and there is not much bend to it. "+
	" It has been pre-shaped for a curvaceous form, wider at the top and"+
	" narrowing towards the waist.%^RESET%^"
	);
	set_weight(5);
	set_value(20);
	set_type("clothing");
	set_limbs(({"torso"}));
	set_ac(1);
	set_wear((:TO,"wearme":));
}

// fixed to use write instead of notify_fail & a couple of TP's to ETO's *Styx*
int wearme(string str)
{
	if((string)ETO->query_gender() != "female") {
		write("This bodice is made for a woman and will not fit a form"+
		" such as yours!\n");
		return 0;
	}
	tell_object(ETO,"You slip into the bodice, tightly lacing it up the front.");
	tell_room(environment(ETO),""+ETO->query_cap_name()+" slips into the"+
	" bodice, tightly lacing up the front.",ETO); 
	return 1;
}
