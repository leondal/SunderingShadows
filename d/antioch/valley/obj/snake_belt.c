#include <std.h>
#include "../valley.h"
inherit "/std/armour";

int FLAG;

void create()
{
	::create();
	set_name("snake skin belt");
	set_id(({"belt","snake belt","snake skin belt","Belt","snakeskin belt","green belt","skin belt"}));
	set_short("%^RESET%^%^GREEN%^A snake skin belt%^RESET%^");
	set_long(
	"%^GREEN%^This belt is made out of a strip of green snake skin."+
	" It is striped with lighter and darker shades of green and is"+
	" quite pretty. It joins together seamlessly in the front to"+
	" look as though it's one continuous strip.%^RESET%^"
	);
	set_weight(3);
	set_size(-1);
	set_type("clothing");
	set_item_bonus("spell damage resistance",15);
	set_limbs(({"waist"}));
	set_ac(0);
	set_value(70);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
	tell_object(ETO,"%^GREEN%^The snake skin belt curls around your"+
	" waist, fitting your body perfectly and joining together"+
	" seamlessly of its own accord.");
	tell_room(environment(ETO),"%^GREEN%^As "+ETO->query_cap_name()+""+
	" moves to put on "+ETO->query_possessive()+" snake skin belt,"+
	" it slides around "+ETO->query_possessive()+" waist of its own"+
	" accord.",ETO);
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^GREEN%^The snake skin belt seems to hiss"+
	" at you as you remove it.");
	return 1;
}
