//Added Lore - Cythera
#include <std.h>
#include "../valley.h"
inherit "/std/armour";

int FLAG;

void create()
{
	::create();
	set_name("%^GREEN%^green tunic%^RESET%^");
	set_id(({"tunic","green tunic","armor","ranger tunic"}));
	set_short("%^RESET%^%^GREEN%^Tunic of the Forest%^RESET%^");
        set_short("%^RESET%^%^GREEN%^A dark green cotton tunic%^RESET%^");
	set_long(
	"The tunic is a dark green in color. It is cut in the"+
	" standard pattern except for the neckline which can lace"+
	" up or be left open if the wearer got hot. It looks like"+
	" it's made out of a rough cotton fabric, but feels smooth"+
	" when you touch it."
	);
	set_lore("Woven by the dryads of the Moonstone Valley, "+
		"this tunic is said to be enchanted with the bounty and"+
		" richness of nature.  Upon request by the Swanmays, the"+
		" dryads have woven into the tunic a special gift to those"+
		" who guard nature.  While all may wear the tunic, it is "+
		"only the rangers who will feel truly comfortable in this"+
		" garment.  The rustic style garment is designed for "+
		"utilitarian sake, rather than fashion.");
	set_property("lore",8);
	set_weight(5);
	set_type("clothing");
	set_limbs(({"torso"}));
	set_value(120);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
        set_property("enchantment",3);
//        set_ac(-2);
	set_size(2);
}

int wearme()
{
        if((string)ETO->query_name() == "swanmay") return 1;
        if(ETO->query_lowest_level() < 15) {
		tell_object(ETO,"You are not yet experienced enough to use this equipment.");
		return 0;
	}
	if(ETO->is_class("ranger") || ETO->is_class("druid")) {
		tell_object(ETO,"%^BOLD%^The tunic looks good on you and"+
		" feels very soft.");
		return 1;
	}
	else {
		tell_object(ETO,"%^BOLD%^The tunic is a little"+
		" uncomfortable.");
   if((int)TO->query_property("enchantment")) {
     while((int)TO->query_property("enchantment") != 2) {
       TO->remove_property("enchantment");
       TO->set_property("enchantment",2);
     }
   }
		return 1;
	}
}

int removeme()
{
	if(ETO->is_class("ranger") || ETO->is_class("druid")) {
		tell_object(ETO,"Your skin gets cold as you remove the"+
		" tunic.");
		return 1;
	}
	else {
		tell_object(ETO,"You remove the scratchy tunic happily.");
   if((int)TO->query_property("enchantment")) {
     while((int)TO->query_property("enchantment") != 3) {
       TO->remove_property("enchantment");
       TO->set_property("enchantment",3);
     }
   }
		return 1;
	}
}
