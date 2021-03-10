//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit S_WANDER;

int SLEEP = 0;

void create()
{
    ::create();
    set_name("sandman");
    set_id(({ "sandman", "monster", "sand man", "construct" }));
    set_short("A sandman");
    set_long(
        "The sandman has humanoid features, but is made entirely out" +
        " of sand and held together by some form of magic. Its eyes" +
        " are featureless sand and stare at you coldly, not appearing" +
        " to move. The creature has no hair to speak of, completely" +
        " bald. Its face is totally expressionless."
        );
    set_gender("neuter");
    set_race("sandman");
    set_body_type("humanoid");
    set_hd(15, 6);
    set_max_level(25);
    set_size(2);
    set_overall_ac(3);
    set_alignment(5);
    set_property("swarm", 1);
    set("aggressive", 11);
    set_mob_magic_resistance("average");
    add_money("electrum", random(1900) + 100);
    set_max_hp(random(40) + 80);
    set_hp(query_max_hp());
    set_level(15);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_damage(1, 8);
    set_hit_funcs((["right hand" : (: TO, "sleep" :)]));
    set_funcs(({ "sleepy" }));
    set_func_chance(10);
//	set_exp(3700);
    set_new_exp(20, "normal");
}

int sleep(object targ)
{
    if (!"daemon/saving_d"->saving_throw(targ, "spell")) {
        tell_object(targ, "You feel very sleepy and decide to" +
                    " take a nap.");
        targ->set_paralyzed(roll_dice(1, 6) * 8, "You are dozing off!");
        tell_room(ETO, "" + targ->query_cap_name() + "" +
                  " falls asleep.", targ);
        return 1;
    }else {
        tell_object(targ, "You resist the urge to take a nap.");
        return 1;
    }
}

void sleepy(object targ)
{
    int i, j;
    object* inven;

    inven = all_living(ETO);
    j = sizeof(inven);

    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i] == TO) {
            continue;
        }
        if (SLEEP == 0) {
            if (!"daemon/saving_d"->saving_throw(inven[i], "spell")) {
                tell_object(inven[i], "You feel very sleepy and" +
                            " decide to take a nap.");
                inven[i]->set_paralyzed(200, "You are asleep!");
            }else {
                tell_object(inven[i], "You manage to stay awake" +
                            " despite the sandman's attempts.");
            }
            SLEEP = 1;
            return 1;
        }else {
            return 1;
        }
    }
}
