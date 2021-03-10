#include <std.h>
inherit WEAPONLESS;

void create(){
	::create();

set_name("donner");
set_id(({"donner","man"}));
set_short("%^BOLD%^%^BLACK%^Donner, the Gentleman's Bodyguard%^RESET%^");
set("long", "%^BOLD%^%^BLACK%^Donner is the Gentleman's personal bodyguard, and he is as %^RESET%^%^RED%^nasty %^BOLD%^%^BLACK%^as they come. He wears %^RESET%^studded leather armor %^BOLD%^%^BLACK%^and %^RESET%^heavy boots %^BOLD%^%^BLACK%^but you can't help but notice he doesn't carry any weapons.%^RESET%^");
set("race","human");
set_body_type("human");
set_hd(20,1);
set_overall_ac(7);
set_size(2);
set_stats("strength" , 18);
set_stats("dexterity", 16);
set_max_hp(150);
set_hp(150);
set_new_exp(12, "boss");
set("aggressive", 15);
set_property("swarm", 1);
set_gender("male");
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand","right foot","left foot"}));
    set_attacks_num(3);
    set_damage(1,6);
}
