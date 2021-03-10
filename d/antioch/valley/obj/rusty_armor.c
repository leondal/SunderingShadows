#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("rusty armor");
	set_id(({"armor","rusty armor","rusty plate","rusty field plate","plate","field plate"}));
	set_short("A suit of rusty armor");
	set_long(
	"This set of field plate is completely covered in dirt and rust."+
	" You imagine that it's been corrupted and polluted by the foul"+
	" beast that wore it to his grave. The field plate might once"+
	" have been quite protective and clean, you can barely make out"+
	" the symbol of some bird of prey beneath the rust and grime."+
	" Right now it's very much in need of a good polish."
	);
	set_weight(60);
	set_ac(2);
        set_armor_prof("heavy");
set_max_dex_bonus(3);
	set_property("enchantment",-1);
	set_value(60);
	set_cointype("copper");
	set_size(2);
	set_type("armour");
	set_limbs(({"torso"}));
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
	tell_object(ETO,"%^ORANGE%^As you slide into the suit of rusty"+
	" armor it almost falls apart on you!");
	tell_room(environment(ETO),"%^ORANGE%^As "+ETO->query_cap_name()+""+
	" gets into the suit of rusty armor it almost falls apart!",ETO);
	return 1;
}

int removeme()
{
	tell_object(ETO,"You're glad to be rid of such a vile thing.");
	return 1;
}
