#include <std.h>
#include "../marsh.h"

inherit WEAPONLESS;

void create()
{
    int my_hd;
    my_hd = roll_dice(1, 8) + 10;
    :: create();
    set_name("mound");
    set_id(({ "mound", "shambling mound", "shambler" }));
    set_short("%^RESET%^%^ORANGE%^Shambling mound%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^The shambling mound is dressed in rotting robes "
             "and armour.  It stares through hollow eyes at its surroundings and "
             "seems to carry an aura of power that is stronger than the "
             "average creature.  It is composed entirely of swamp vegetation and "
             "smells horrible.%^RESET%^");
    set("aggressive", random(10) + 9);
    set_gender("male");
    set_level(my_hd);
    set_weight(175);
    set_attacks_num(my_hd / 7 + 2);
    set_damage(3, my_hd / 2);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({ "right hand", "left hand" }));
    set_overall_ac(5 - my_hd);
    set_stats("strength", my_hd + 4);
    set_alignment(6);
    set_race("shambler");
    set_body_type("humanoid");
    set_class("fighter");
    this_object()->add_money("gold", roll_dice(10, my_hd) + 200);
    set_guild_level("fighter", my_hd);
    set_hd(my_hd, 5);
    set_max_hp(my_hd * 15 + 100);
    set_hp(my_hd * 15 + 100);
    //set_exp(5500);
    set_new_exp(my_hd, "high");
    set_max_level(18);
    set_emotes(4, ({ "%^RED%^The shambling mound lashes at your face!%^RESET%^",
                     "%^RED%^%^BOLD%^The shambling mound claws at your face!%^RESET%^",
                     "%^GREEN%^%^BOLD%^You feel sick and dizzy!%^RESET%^" }), 1);
    set_funcs(({ "special" }));
    set_func_chance(25);
}

int special(object vic)
{
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(vic)) {
        return 1;
    }

    switch (random(2)) {
    case 0:

        TO->force_me("emote rumbles a deep growl that vibrates the earth itself!");
        TO->add_hp(roll_dice(5, 10));
        tell_room(ETO, "%^GREEN%^Shambling Mound is revitalized by the marsh!%^RESET%^");
        return 1;

    case 1:

        TO->force_me("grin");
        tell_room(ETO, "%^BOLD%^%^GREEN%^The shambling mound covers " + vic->QCN + " "
                  "with slime!%^RESET%^", vic);
        tell_object(vic, "%^BOLD%^%^GREEN%^The shambling mound covers you with "
                    "slime!%^RESET%^");
        vic->do_damage(vic->return_target_limb(), roll_dice(5, 10));
        if (!REFLEX(vic, -15)) {
            vic->set_paralyzed(random(8) + 6, "You are weak from the slime!");
        }
        return 1;
    }
}

int agg_fun(object ob)
{
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ob)) {
        return 1;
    }
    if (ob->query_invis()) {
        return 1;
    }

    TO->kill_ob(ob, 0);

    tell_object(ob, "%^BOLD%^%^GREEN%^The shambling mound envelopes "
                "you!%^RESET%^");
    ob->do_damage("torso", random(15) + 2);
    if (!REFLEX(ob, -15)) {
        ob->set_paralyzed(random(4) + 1, "%^GREEN%^You are trying to get away!%^RESET%^");
    }
    return 1;
}
