#include <std.h>

inherit "/std/trainer";

void create(){
    ::create();

    set_name("vaistus");
    set_short("Vaistus the trainer");
    set_long("Vaistus is a huge man, scarred from battle. He is constantly training with adventurers or any who pass through his arena.");
    set_hd(35,5);
    set_stats("strength", 12);
    set_max_hp(300);
    set_hp(300);
    set_attack_limbs(({"right hand","left hand"}));
    set_attacks_num(2);
    set_damage(1,1);
    set_race("human");
    set_gender("male");
    set_id( ({"vaistus", "Vaistus", "trainer", "master"}) );
    set_base_damage_type("bludgeoning");
    set_overall_ac(5);
    set_exp(1);
}
