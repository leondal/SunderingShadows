#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("colorful skirt");
   set_short("%^YELLOW%^A %^RED%^c%^YELLOW%^o%^MAGENTA%^l%^YELLOW%^o%^RED%^r%^MAGENTA%^f%^YELLOW%^u%^RED%^l%^YELLOW%^ skirt%^RESET%^");
	set_id(({"colorful skirt","skirt","clothing","mina_clothing","cotton skirt","colorful cotton skirt","long skirt"}));
	set_long(
	"%^BOLD%^%^WHITE%^This beautiful skirt has been dyed several colors. The"+
	" top part starts with %^YELLOW%^yellow%^WHITE%^ and runs into %^RESET%^%^ORANGE%^orange%^BOLD%^%^WHITE%^,"+
	" then to %^RED%^red%^WHITE%^, and finally into a rich %^MAGENTA%^purple%^WHITE%^. Bells have been sewn onto the top of the skirt,"+
	" hanging from little tassels. It tends to make a light tinkling noise"+
	" when you move or twirl around."
	);
	set_weight(2);
	set_value(45);
	set_ac(0);
	set_type("ring");
	set_limbs(({"waist"}));
	set_size(2);
	set_wear((:TO,"wearme":));
    set_property("repairtype",({ "tailor" }));
}

void init()
{
	::init();
	add_action("twirl","twirl");
}

int wearme(string str)
{
	if((string)ETO->query_gender() != "female") {
		notify_fail("This skirt is for a lady, it doesn't fit you.\n");
		return 0;
	}
	tell_object(ETO,"%^BOLD%^The bells jingle as you put the skirt on, you"+
		" almost feel like %^MAGENTA%^twirl%^WHITE%^ing.");
	tell_room(environment(ETO),"%^BOLD%^The bells on "+ETO->query_cap_name()+"'s"+
	" skirt jingle as she puts it on.",ETO);
	return 1;
}

int twirl(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}

	if(query_worn() && !str) {
		tell_object(ETO,"%^YELLOW%^The bells on the skirt jingle as you twirl"+
		" around.");
		tell_room(environment(ETO),"%^YELLOW%^The bells on "+ETO->query_cap_name()+"'s"+
		" skirt jingle as she twirls around.",ETO);
		return 1;
	}
}
