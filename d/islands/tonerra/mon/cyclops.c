//Added set_max_level to retard cycling - Octothorpe 6/4/09
//cyclops.c

#include <std.h>

inherit WEAPONLESS;

void create()
{
    ::create();

    set_name("cyclops");
    set_short("Giant cyclops");
    set_id(({ "cyclops", "Cyclops", "giant", "giant cyclops" }));
    set_long("This massive man like creature is shaped much like an out of shape old man might ... if he weren't 20 feet tall. He is extremely large and very strong.  A single eye peers at you from the center of his head.");
    set_hd(23, 8);
    set_hp(200 + random(20)); // was only 150
    set_exp(10000);
    set_new_exp(25, "very high");
    set_max_level(25);
    set_overall_ac(-6);
    set_body_type("human");
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(2);
    set_damage(6, 6);
    set_base_damage_type("bludgeoning");
    set_size(3);
    set_gender("male");
    set_race("cyclops");
    set_property("swarm", 1);
    set_property("no death", 1);
    add_money("gold", random(800));
    set_speed(40);
}

int query_watched()
{
    return 45;
}

void init()
{
    ::init();
// changing to exclude true_invis *Styx* 12/21/03, last change 7/20/98
    if (TP->query_true_invis()) {
        return;
    }
    if (TP->query_invis() && random(3)) {
        kill_ob(TP, 1);
    }
}
