//ibrandlin.c

#include <std.h>

inherit WEAPONLESS;

void create()
{
    ::create();

    set_name("ibrandlin");
    set_id(({ "ibrandlin", "Ibrandlin" }));
    set_short("%^RESET%^%^ORANGE%^I%^BOLD%^%^ORANGE%^br%^RESET%^%^ORANGE%^a%^BOLD%^%^ORANGE%^ndlin%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This large serpentine monster has six claws that look to rake wildly across anything near it. Hot fumes eminate from within the beast. A great maw looks to bite and lacerate. Red gold scales cover the body, providing a formidable armor. This creature is a creation of some great magic.");
    set_body_type("snake");
    set_alignment(3);
    add_limb("upper left claw", "", 0, 0, 0);
    add_limb("middle left claw", "", 0, 0, 0);
    add_limb("lower left claw", "", 0, 0, 0);
    add_limb("upper right claw", "", 0, 0, 0);
    add_limb("middle right claw", "", 0, 0, 0);
    add_limb("lower left claw", "", 0, 0, 0);
    set_attack_limbs(({ "upper right claw", "middle right claw", "lower right claw", "upper left claw", "lower left claw", "middle left claw", "mouth" }));
    set_base_damage_type("slashing");
    set_attacks_num(7);
    set_damage(3, 8);
    set_hd(35 + random(15), 9);
    set_hp(query_hd() * 25);
    set_hit_funcs((["mouth" : (: TO, "mouth" :)]));
    set_mob_magic_resistance("average");
    set_property("spell damage resistance", 15);
    set_overall_ac(-35);
    set_race("ibrandlin");
    set_gender("male");
    set_exp(400 * query_hd());
    set_new_exp(35, "boss");
    set_max_level(40);
    set_property("no web", 1);
    set("aggressive", 25);
    set_emotes(20, ({ "%^MAGENTA%^Ibrandlin says%^RESET%^: I serve only Ibrandul.", "%^MAGENTA%^Ibrandlin says%^RESET%^: My god is not dead, Shar failed." }), 1);
    set_property("no tripped", 1);
    set_property("no paralyzed", 1);
    set_monster_feats(({
        "damage resistance",
        "regeneration",
        "parry",
        "knockdown",
        "powerattack",
        "daze",
        "dodge",
        "expertise",
        "disarm",
    }));
    set_func_chance(55);
    set_funcs(({ "knockdownit", "dazeit", "disarmit" }));
}

void knockdownit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("knockdown " + targ->query_name());
    TO->continue_attack();
}

void dazeit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("daze " + targ->query_name());
    TO->continue_attack();
}

void disarmit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("disarm " + targ->query_name());
    TO->continue_attack();
}

int query_ibrandul()
{
    return 1;
}

int mouth(object targ)
{
    int i, j;
    object* attack = query_attackers();

    set_property("magic", 1);
    j = sizeof(attack);
    tell_room(ETO, "%^RED%^A huge blast of fire belows forth from the maw of the ibrandlin.");
    for (i = 0; i < j; i++) {
        if (!objectp(attack[i]) || attack[i]->query_true_invis()) {
            continue;
        }
        attack[i]->do_damage("torso", roll_dice(4, 12));
    }

    return random(10);
}
