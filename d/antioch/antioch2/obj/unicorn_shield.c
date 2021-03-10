#include <std.h>
//Updated for armor feats Octothorpe 5/11/09
inherit "/d/common/obj/armour/shield.c";

int FLAG;

void create()
{
	::create();
	set_name("unicorn shield");
	set_short("%^BOLD%^%^WHITE%^Uni%^YELLOW%^c%^WHITE%^orn Shield%^RESET%^");
	set_id(({"shield","unicorn shield","Unicorn shield","Unicorn Shield"}));
	set_long(
	"%^BOLD%^%^WHITE%^This beautiful shield has a rearing unicorn on the"+
	" front of it. The hooves of the unicorn are %^RESET%^silver%^BOLD%^"+
	" and the spiral horn that protrudes from the top of the shield is"+
	" %^YELLOW%^golden%^WHITE%^. This is a shield from the royal guard"+
	" of Antioch.%^RESET%^"
	);
	set_weight(15);
	set_value(40);
        //set_type("shield");
        //set_limbs(({"right hand"}));
        //set_ac(1);
	set_property("enchantment",1);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
   if(ETO->query_lowest_level() < 5) {
		tell_object(ETO,"You are not experienced enough to use this equipment.");
		return 0;
	}
	if(ALIGN->is_good(ETO)) {
		tell_object(ETO,"%^BOLD%^You slip the %^YELLOW%^Unicorn Shield%^WHITE%^"+
		" on your arm in honor.");
		FLAG = 1;
		ETO->add_property("magic resistance",20);
		return 1;
	}
	if(ALIGN->is_evil(ETO)) {
		tell_object(ETO,"%^BOLD%^The shield tightens its grip on your arm as"+
		" you wear it, almost crushing your wrist.");
		ETO->cause_typed_damage(ETO, "torso", roll_dice(1, 5) + 9, "divine");
		return 1;
	}
	return 1;
}

int removeme()
{
	if(ALIGN->is_good(ETO)) {
		tell_object(ETO,"%^BOLD%^You set the %^YELLOW%^Unicorn Shield%^WHITE%^"+
		" aside, feeling a little more vulnerable as you let it go.");
	}
	if(ALIGN->is_evil(ETO)) {
		tell_object(ETO,"You gladly release the Unicorn Shield, feeling the"+
		" blood slowly return to your arm.");
	}
	if(FLAG == 1) {
		ETO->add_property("magic resistance",-20);
		return 1;
	}
	return 1;
}
