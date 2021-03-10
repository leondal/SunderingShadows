#include <std.h>
inherit WEAPONLESS;
void create(){
        ::create();
        set_name("Bugsy");
        set_id(({"bugsy", "man"}));
   set_short("%^BOLD%^%^BLACK%^Bugsy, the Gentleman's Lieutenant%^RESET%^");
        set("long","This is one of the Gentleman's lieutenants. He's dressed %^BOLD%^%^MAGENTA%^impeccably%^RESET%^ in the most %^BOLD%^expensive%^RESET%^ clothes that money can buy.");
        set("race","human");
set_body_type("human");
        set_hd(20,1);
set_overall_ac(7);
        set_size(3);
        set_stats("strength", 18);
        set_max_hp(230);
        set_hp(230);
        set_max_sp(55);
        set_new_exp(12, "boss");
        set("agressive", 10);
        set_property("swarm", 1);
        set_gender("male");
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand","right foot","left foot"}));
    set_attacks_num(3);
    set_damage(1,6);
}
