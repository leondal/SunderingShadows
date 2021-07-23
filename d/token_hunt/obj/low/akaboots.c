#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^CYAN%^sky-blue leather boots%^RESET%^");
	set_id(({ "boots", "shoes", "roar of the winds", "sky-blue boots" }));
	set_short("%^BOLD%^%^BLUE%^R%^RESET%^%^BLUE%^o%^CYAN%^a%^BOLD%^%^CYAN%^r %^WHITE%^o%^RESET%^%^WHITE%^f %^BLUE%^t%^BOLD%^%^BLUE%^h%^CYAN%^e %^RESET%^%^CYAN%^W%^WHITE%^i%^BOLD%^%^WHITE%^n%^BLUE%^d%^RESET%^%^BLUE%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^sky-blue leather boots%^RESET%^");
	set_long("%^RESET%^%^CYAN%^Rarely are found such a fine pair of boots. The soft, %^BOLD%^%^BLUE%^deep blue leather%^RESET%^%^CYAN%^ has been treated with care to make it incredibly lightweight and flexible, while the insides have been lined with %^BOLD%^%^CYAN%^soft a%^RESET%^%^CYAN%^z%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^e silk%^RESET%^%^CYAN%^ for added comfort. Polished %^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^u%^CYAN%^r%^BOLD%^%^CYAN%^%^GREEN%^q%^RESET%^"
"%^GREEN%^u%^CYAN%^o%^BOLD%^%^CYAN%^i%^BLUE%^s%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^ clasps%^RESET%^%^CYAN%^ line the sides and can be adjusted to a perfect fit. Much like %^RESET%^c%^BOLD%^%^BLACK%^l%^WHITE%^ou%^BLACK%^d%^RESET%^s%^CYAN%^ move languidly through the %^BOLD%^%^CYAN%^infinite sky%^RESET%^%^CYAN%^, the blue of these fine boots seem to %^BOLD%^%^BLUE%^shift%^RESET%^%^CYAN%^ in hue, an endless cycle of %^BOLD%^%^WHITE%^l%^RESET%^i%^BOLD%^%^BLACK%^g%^RESET%^h%^BOLD%^%^WHITE%^t%^RESET%^%^CYAN%^ and %^BOLD%^%^BLACK%^d%^RESET%^a%^BOLD%^r%^BOLD%^%^BLACK%^k%^RESET%^%^CYAN%^.%^RESET%^");
	set_weight(2);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^CYAN%^Oddly enough, these boots seemed to have transpired out of thin air and have been a mystery ever since. Many speculate that the Queen of the Air herself blessed the world with this unique gift although that has never been proven, and, although many Akadian priests have attempted to discover their origin, they eventually grew bored with the project and moved onto some new fascination, leaving the mystery unsolved.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",8);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^Buckling the boots, you're astonished by how comfortable they feel.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You slip off the boots, tossing them aside.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 500){
	tell_room(environment(query_worn()),"%^RESET%^%^CYAN%^With a deft swing of the leg, "+ETOQCN+"%^RESET%^%^CYAN%^ lands a solid kick making "+who->QCN+"%^RESET%^%^CYAN%^ double over in pain.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^CYAN%^Turning to deflect "+who->QCN+"'s%^RESET%^%^CYAN%^ attack, you swing your leg around, landing a solid blow.%^RESET%^");
	tell_object(who,"%^RESET%^%^CYAN%^A quick kick sends you reeling in pain.%^RESET%^");
		who->set_paralyzed(random(12));
return damage;	}
}