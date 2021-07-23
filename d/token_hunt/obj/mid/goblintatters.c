#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("leather foot wraps");
	set_id(({ "foot wraps", "wraps", "shoes", "tatters", "tatters of the goblin trader" }));
	set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^GREEN%^a%^RESET%^t%^BOLD%^%^BLACK%^ters of the G%^RESET%^%^GREEN%^o%^RESET%^b%^BOLD%^%^BLACK%^lin T%^RESET%^%^GREEN%^r%^RESET%^a%^BOLD%^%^BLACK%^der%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^ratty leather foot wraps%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Some might call these foot coverings, shoes, but they are little more then several strips of ragged %^RESET%^%^GREEN%^gr%^BOLD%^%^BLACK%^e%^RESET%^e%^GREEN%^ni%^BOLD%^%^BLACK%^s%^RESET%^%^GREEN%^h b%^BOLD%^%^BLACK%^l%^RESET%^a%^GREEN%^ck %^BOLD%^%^BLACK%^scale covered leather that has been loosely stitched together to form some mild protection for the feet.  Bands of black and green weave between each other, stretching from a thicker sole of the same leathery substance.  A small piece of %^RESET%^%^CYAN%^metal %^BOLD%^%^BLACK%^has been formed into a loose curve at the toe and heel to give additional protection, but otherwise the shoe is rather %^RESET%^fragile %^BOLD%^%^BLACK%^looking.  Strangely, %^RESET%^%^CYAN%^p%^GREEN%^a%^RESET%^i%^CYAN%^nt%^GREEN%^e%^CYAN%^d b%^GREEN%^e%^RESET%^a%^CYAN%^ds %^BOLD%^%^BLACK%^of %^RESET%^hollowed bone %^BOLD%^%^BLACK%^are set into the laces and, even with an untrained eye, one can see these hold %^RESET%^%^GREEN%^power %^BOLD%^%^BLACK%^within.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(0);
	set_lore(
@AVATAR
Goblins are noxious little creatures to be sure, but sometimes they come up with the most interesting of things.  In this case, a goblin slave trader who suffered a great loss when his entire inventory was lost to freak storm that set his wooden cages on fire and cooked the contents within.  That these were Alu-Tel-Quessir (sea elves) was at first seen as a great loss and he was nearly ruined because of it.  Except that he realized their scaly hides had been boiled and hardened by the fire.  So, in an effort to recoup his losses, he had the bodies skinned and used the metal pieces that were left over from the cage to make a large supply of footwear for a large goblin raiding party.

AVATAR
	);
	set_property("lore difficulty",18);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" pulls the leather wraps of their shoes on and looks down in amazement.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you slip your boots on the %^RESET%^%^CYAN%^p%^GREEN%^a%^RESET%^i%^CYAN%^nt%^GREEN%^e%^CYAN%^d b%^GREEN%^e%^RESET%^a%^CYAN%^ds %^BOLD%^%^BLACK%^of %^RESET%^hollowed bone %^BOLD%^%^BLACK%^come to life and begin to float in the air as though they were within water.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A soft clatter of tiny bones issues as "+ETOQCN+" draws off their "+query_short()+"%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^p%^GREEN%^a%^RESET%^i%^CYAN%^nt%^GREEN%^e%^CYAN%^d b%^GREEN%^e%^RESET%^a%^CYAN%^ds %^BOLD%^%^BLACK%^of %^RESET%^hollowed bone %^BOLD%^%^BLACK%^ stop moving on the unfelt current and clatter down about your feet.%^RESET%^");
	return 1;
}