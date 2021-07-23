#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^RED%^c%^MAGENTA%^r%^WHITE%^o%^MAGENTA%^w%^RED%^n of r%^MAGENTA%^o%^WHITE%^s%^MAGENTA%^e%^RED%^s%^RESET%^");
	set_id(({ "crown", "crown of roses", "roses" }));
	set_short("%^RESET%^%^RED%^c%^MAGENTA%^r%^WHITE%^o%^MAGENTA%^w%^RED%^n of r%^MAGENTA%^o%^WHITE%^s%^MAGENTA%^e%^RED%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^c%^MAGENTA%^r%^WHITE%^o%^MAGENTA%^w%^RED%^n of r%^MAGENTA%^o%^WHITE%^s%^MAGENTA%^e%^RED%^s%^RESET%^");
	set_long("%^BOLD%^%^MAGENTA%^Pink%^RESET%^%^MAGENTA%^, %^RESET%^white%^MAGENTA%^ and %^RED%^red%^MAGENTA%^ miniature %^BOLD%^%^MAGENTA%^r"
"%^RESET%^%^RED%^o%^MAGENTA%^s%^RED%^e%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^ have been magically weaved together to create this %^RESET%^d"
"%^BOLD%^el%^RESET%^ic%^BOLD%^at%^RESET%^e%^MAGENTA%^ crown. No thorns or greenery can be found, and the %^BOLD%^%^MAGENTA%^soft petals"
"%^RESET%^%^MAGENTA%^ of the flowers seem never to wilt. Slender %^RESET%^s%^MAGENTA%^i%^RED%^l%^RESET%^k%^MAGENTA%^ ribbons of matching "
"%^BOLD%^%^MAGENTA%^c%^RESET%^o%^BOLD%^%^RED%^lo%^RESET%^r%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^ cascade down the back of the crown, to mingle "
"within the wearer's hair and fall down her back. The crown fills the air with a %^RESET%^l%^BOLD%^o%^RESET%^ve%^BOLD%^l%^RESET%^y%^MAGENTA%^ "
"scent of roses.%^RESET%^");
	set_weight(2);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
      set_item_bonus("charisma",1);
	set_wear((:TO,"wear_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^The room suddenly smells like %^RED%^roses%^MAGENTA%^!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The pleasant aroma of %^RESET%^%^MAGENTA%^roses %^BOLD%^%^RED%^wafts through the air.%^RESET%^");
	return 1;
}

int remove_func(){
	return 1;
}