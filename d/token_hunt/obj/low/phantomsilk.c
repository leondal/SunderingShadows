#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("silk cloak");
	set_id(({ "phantom silk", "cloak", "silk cloak", "phantom silk cloak" }));
	set_short("%^BOLD%^%^BLACK%^Ph%^RESET%^%^RED%^a%^RESET%^n%^RED%^t%^BOLD%^%^BLACK%^om S%^RESET%^%^RED%^i%^RESET%^l%^BOLD%^%^BLACK%^k C%^RESET%^%^RED%^l%^RESET%^o%^RED%^a%^BOLD%^%^BLACK%^k%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a d%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^rk colored cl%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^ak made of s%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^lk%^RESET%^");
	set_long("%^RESET%^%^BLUE%^The material of this cloak glistens with a %^CYAN%^liquid %^BLUE%^like quality. Thinner than silk, the cloak is surprisingly sturdy and full, encompassing its wearer in an %^BOLD%^%^BLACK%^inky blackness %^RESET%^%^BLUE%^highlighted by a cobweb of %^BOLD%^%^RED%^crimson %^RESET%^%^BLUE%^threads.  In motion, the cloak sweeps out behind its wearer in the dramatic display of a trailing %^BOLD%^%^BLACK%^shadow%^RESET%^%^BLUE%^, while settled about the shoulders the cloak provides the %^RED%^%^BOLD%^disconcerting %^RESET%^%^BLUE%^sensation of being shrouded in living %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^. An enveloping hood can be drawn upward, further adding to this impression.  Curiously, there seems to be enough material within the hood's fold that a small item might be hidden there.%^RESET%^");
	set_weight(2);
	set_value(0);
	set_lore("The drow wizard Itl'ezakynt is credited with creating the Phantom Silk cloaks.  Through a disturbing ritual in which the very essence of a sentient being is siphoned from the still living host, a thread is created which can be woven only on a loom made from the enchanted bones of the dead host.  The weaving process takes over a month's time during which only one cloak is created.  That cloak is unique however as it imbues its wearer with some of the properties of the sacrificed creature.");
	set_property("lore difficulty",12);
	set_max_internal_encumbrance(5);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_item_bonus("charisma",1);
   set_overallStatus(220);
   set_property("no disenchant",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+" slips a lightweight cloak about their shoulders, something else seems to settle there as well.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel that the very shadows lend themselves to your aura as you slip the lightweight cloak about your shoulders.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Something seems to slip away from "+ETOQCN+"'s shoulders even as they draw the cloak from their shoulders.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Pulling the cloak from your shoulders, you can't help but feel as though something else is drawn away well.%^RESET%^");
	return 1;
}