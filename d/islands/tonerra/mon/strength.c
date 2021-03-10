//strength.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("guardian of strength");
    set_short("Guardian of strength");
    set_id(({ "guardian", "strength", "guardian of strength" }));
    set_long("This huge creature is the guardian of strength. The monks physical strength and fortitude. With that responsiblity come the awesome power of the monks strength. Great rippling muscles bulge from this humanoid. This creature must be able to withstand great assaults and take great amounts of damage. It is here to guard the strength of the monks.");
    set_race("guardian");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(-15);
    set_hd(55, 1);
    set_hp(550);
    set_exp(45000);
    set_max_level(36);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(2);
    set_damage(2, 15);
    set_base_damage_type("bludgeoning");
    set_funcs(({ "slam" }));
    set_func_chance(35);
    set_stats("dexterity", 1);
    set_stats("wisdom", 1);
    set_stats("intelligence", 1);
    set_stats("charisma", 1);
    new(MONASTERY + "str")->move(TO);
    set_new_exp(35, "boss");
}

void init()
{
    ::init();
    if (!TP->query_true_invis() && member_array("guardian", (string*)TP->query_id()) == -1) {
        kill_ob(TP, 1);
    }
}

void set_paralyzed(int time, string message)
{
    ::set_paralyzed(time / 2, message);
}

int do_damage(string limb, int dam)
{
    if (base_name(PO) == "/cmds/assassin/_stab" || base_name(PO) == "/cmds/thief/_stab") {
        return ::do_damage(limb, 999999);
    }
    if (PO->is_spell()) {
        return ::do_damage(limb, dam);
    }

    return ::do_damage(limb, dam / 2);
}

void slam(object targ)
{
    if (!objectp(targ)) {
        return;
    }

    if (!interactive(targ)) {
        execute_attack();
        execute_attack();
        return;
    }

    tell_room(ETO, "%^RED%^The guardian picks " + targ->query_cap_name() + " up and in a great strong motion slams " + targ->query_objective() + " in to the floor with horrid viciousness.", targ);
    tell_object(targ, "%^RED%^The guardian picks you up with ease and slams you flat onto your back with horrid visiousness. You are paralyzed by the pain rushing up and down your spine.");
    targ->do_damage("torso", roll_dice(5, 10));
    targ->set_paralyzed(random(30), "%^RED%^The vicous blow of the guardian has cut some feeling to your limbs.");
    return;
}
