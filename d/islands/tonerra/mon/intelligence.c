//strength.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void psionics(object targ);

void create()
{
    ::create();
    set_name("guardian of intelligence");
    set_short("Guardian of intelligence");
    set_id(({ "guardian", "intelligence", "guardian of intelligence" }));
    set_long("This is the guardian of intelligence. Middle aged, with deep set eyes. He seems studied and smart. His studies have more then likely left him with a strong knowledge of mystic arts. You can feel the force of his in probing you.");
    set_race("guardian");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(-14);
    set_hd(55, 1);
    set_class("thief");
    set_mlevel("mage", 90);
    set_hp(550);
    set_exp(45000);
    set_new_exp(35, "boss");
    set_max_level(36);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(2);
    set_mob_magic_resistance("average");
    set_damage(2, 5);
    set_base_damage_type("bludgeoning");
    set_stats("dexterity", 100);
    set_funcs(({ "spells", "psionics" }));
    set_func_chance(15);
    set_stats("wisdom", 25);
    set_stats("intelligence", 25);
    set_stats("charisma", 1);
    set_stoneSkinned(10);
    new(MONASTERY + "int")->move(TO);
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
    tell_room(ETO, "%^BOLD%^The paralysis has no effect.");
    return;
}

int do_damage(string limb, int dam)
{
    if (base_name(PO) == "/cmds/assassin/_stab" || base_name(PO) == "/cmds/thief/_stab") {
        return ::do_damage(limb, dam / 3);
    }
    if (PO->is_spell()) {
        return ::do_damage(limb, dam / 2);
    }

    return ::do_damage(limb, dam);
}

void spells(object targ)
{
    if (targ->query_property("magic resistance") > 50) {
        return psionics(targ);
    }
    switch (random(10)) {
    case 0:
        new("/cmds/spells/l/_lightning_bolt")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        new("/cmds/spells/l/_lightning_bolt")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;

    case 1:
        new("/cmds/spells/m/_magic_missile")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        new("/cmds/spells/m/_magic_missile")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;

    case 2:
        new("/cmds/spells/f/_fireball")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        new("/cmds/spells/f/_fireball")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;

    case 3:
        new("/cmds/spells/c/_cone_of_cold")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        new("/cmds/spells/c/_cone_of_cold")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;

    case 4:
        new("/cmds/spells/p/_powerword_stun")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        new("/cmds/spells/p/_powerword_stun")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;

    case 5:
        new("/cmds/spells/i/_ice_storm")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;

    case 6:
        new("/cmds/spells/m/_meteor_swarm")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        new("/cmds/spells/m/_meteor_swarm")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;

    case 7:
        new("/cmds/spells/c/_chain_lightning")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        new("/cmds/spells/c/_chain_lightning")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;

    case 8:
        new("/cmds/spells/v/_vampiric_touch")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        new("/cmds/spells/v/_vampiric_touch")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;

    case 9:
        new("/cmds/spells/i/_incendiary_cloud")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        new("/cmds/spells/i/_incendiary_cloud")->use_spell(TO, targ->query_name(), 54, 100, "mage");
        break;
    }
}

void psionics(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    set_property("magic", 1);
    switch (random(3)) {
    case 0:
        tell_room(ETO, "%^BOLD%^%^CYAN%^A wave of energy rushes out from the guardian toward " + targ->query_cap_name() + ".", targ);
        tell_object(targ, "%^BOLD%^%^CYAN%^A rush of energy comes from the guardian toward you.");
        targ->do_damage("torso", roll_dice(3, 15));
        return;

    case 1:
        tell_room(ETO, "%^BOLD%^%^MAGENTA%^A flush of energy grabs hold of " + targ->query_cap_name() + "'s head.", targ);
        tell_object(targ, "%^BOLD%^%^MAGENTA%^A flush of energy grabs hold of your head holding you capturing your thoughts.");
        targ->set_paralyzed(roll_dice(15, 2), "%^MAGENTA%^Your mind is held.%^RESET%^");
        targ->do_damage("torso", roll_dice(2, 10));

    case 2:
        tell_room(ETO, "%^BOLD%^%^YELLOW%^A seering shot of energy shoots toward " + targ->query_cap_name() + ".", targ);
        tell_object(targ, "%^BOLD%^%^YELLOW%^A seering shot of energy crashes into you and burns at your innards.");
        targ->do_damage("torso", roll_dice(6, 10));
    }
}
