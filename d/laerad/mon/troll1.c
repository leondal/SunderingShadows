//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
void create()
{
    ::create();
    set_id(({ "troll", "peasant", "troll peasant" }));
    set_name("troll peasant");
    set_short("A Troll peasant");
    set_long(
        "This is a scrawny troll peasant.  He is dressed in tattered " +
        "rags.  His skin is a putred green and his eyes bulge out of his " +
        "head.  He stands nearly 6 feet tall but is small for a troll."
        );
    set_body_type("human");
    set_race("troll");
    set_gender("male");
    set_size(2);
    set_hd(8, 6);
    set_hp(70);
    set_overall_ac(0);
    set_resistance_percent("fire", -50);
    set_resistance_percent("acid", -50);
    set_exp(0);
    set_stats("strength", 19);
    set_stats("constitution", 24);
    set_property("swarm", 1);
    add_money("gold", random(50) + 10);
    add_money("silver", random(20) + 10);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "right hand", "left hand", "head" }));
    set_attacks_num(3);
    set_damage(1, 4);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
}

void init()
{
    string race;
    ::init();
    race = (string)TP->query_race();
    if (wizardp(TP)) {
        return;
    }
    if (TP->query_invis()) {
        return;
    }
    if (race == "human" || race == "elf" || race == "half-elf" ||
        race == "dwarf" || race == "gnome" || race == "halfling" ||
        race == "horse") {
        if (interactive(TP)) {
            force_me("say YOU DO NOT BELONG HERE OUTSIDER!");
        }
        force_me("kill " + TPQN);
        return 1;
    }
    if (interactive(TP)) {
        force_me("bow");
    }
    force_me("say hello friend.");
    return 1;
}

void heart_beat()
{
    ::heart_beat();
    if (query_hp() < 70) {
        add_hp(2);
        return;
    }
}

void die(object targ)
{
    if (query_hp() < -15) {
        query_current_attacker()->add_exp(500);
        return ::die(targ);
    }
    tell_room(ETO, "%^RED%^Troll peasant drops dead before you.");
    new("/d/laerad/mon/obj/tcorpse")->move(ETO);
    remove();
}
