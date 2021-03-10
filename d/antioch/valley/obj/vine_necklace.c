#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   	set_name("necklace of vines");
   	set_short("%^RESET%^%^GREEN%^Necklace of %^BOLD%^Vines%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A necklace made of vines%^RESET%^");
   	set_id(({"necklace","necklace of vines","vine necklace"}));
   	set_long("%^BOLD%^%^GREEN%^This is a very unusual necklace of living vines. All the"+
   		" vines appear quite healthy, with delicate leaves and sometimes"+
   		" even a few small %^BLUE%^f%^RESET%^%^MAGENTA%^l%^BOLD%^"+
		"%^WHITE%^o%^CYAN%^w%^BLUE%^e%^RESET%^%^MAGENTA%^r%^BOLD%^"+
		"%^WHITE%^s%^GREEN%^. They form a necklace of sorts that"+
   		" could fit around the neck of an average person...if they're"+
   		" willing to put such a thing so close to them.%^RESET%^\n");
	set_lore("Woven from the vines that grow wild in the valley, "+
		"these necklaces are crafted by the dryads.  The verdant"+
		" green vines are interwoven with flowering vines to create"+
		" a beautiful display of natures' bounty.  After the problems"+
		" weight down on the valley, the dryads found their beautiful"+
		" necklaces needed to protect as well, and put their fey magic"+
		" to use.  These necklaces are quite popular with nature oriented"+
		" folk.");
   set_type("clothing");
   set_limbs(({"neck"}));
   set_weight(2);
   set_ac(0);
   set_property("enchantment",2);
   set_item_bonus("magic resistance",1);
   set_value(1500);
   set_wear((: TO,"wear_func" :));
   set_remove((: TO,"remove_func" :));
}

int wear_func() {
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^ Vines curl protectivly"+
		" around "+ETOQCN+"'s neck.",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^The vines curl delicately around your neck.");
   	return 1;
}

int remove_func() {
   tell_room(environment(ETO),"%^BOLD%^%^GREEN%^The vine carefully detach "+
		"themselves from "+ETOQCN+"'s neck.",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^The vines carefully detach themselves"+
		" from your neck.");
   return 1;
}
