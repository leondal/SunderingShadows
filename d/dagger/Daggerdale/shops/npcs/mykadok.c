#include <std.h>

inherit "/std/trainer";

void create(){
    ::create();

    set_name("mykadok");
    set_short("Mykadok the trainer");
    set_long(
      "Mykadok is a gigantic man, scarred from battle and missing several teeth."
    );
    set_hd(35,5);
    set_stats("strength", 12);
    set_max_hp(300);
    set_attack_limbs(({"right hand","left hand"}));
    set_attacks_num(2);
    set_damage(1,1);
    set_race("human");
    set_gender("male");
    set_id( ({"mykadok", "Mykadok", "trainer", "master"}) );
    set_base_damage_type("bludgeoning");
    set_overall_ac(5);
    set_exp(1);
}
