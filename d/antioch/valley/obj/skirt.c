#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("purple skirt");
	set_id(({"skirt","sirine skirt","purple skirt","slit skirt"}));
	set_short("%^MAGENTA%^A purple skirt%^RESET%^");
	set_long(
	"%^MAGENTA%^The skirt is pretty, even if it wouldn't cover"+
	" very much. The color ranges from a dark purple at the"+
	" very bottom up to a lavander at top. The sides are completely"+
	" slit and there isn't much material left to cover the"+
	" rest of a woman's body.%^RESET%^"
	);
	set_type("ring");
	set_size(2);
	set_limbs(({"waist"}));
	set_value(60);
	set_weight(3);
	set_property("enchantment",random(3));
	set_wear((:TO,"wearme":));
}

int wearme(string str)
{
	if((string)ETO->query_gender() != "female") {
		tell_object(ETO,"The skirt just doesn't seem to fit"+
		" your hips.");
		return 0;
	}
	else {
		tell_object(ETO,"The skirt fits you perfectly.");
		return 1;
	}
}

void init()
{
	::init();
	add_action("sit","sit");
}

int sit(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if((string)ETO->query_gender() == "female" && query_worn() && !str) {
		write("%^MAGENTA%^You sit down, giving everyone an even"+
		" better view of your legs.");
		say("%^MAGENTA%^"+ETO->query_cap_name()+" sits down,"+
		" giving you a great view of "+ETO->query_possessive()+""+
		" legs.");
		return 1;
	}
}
