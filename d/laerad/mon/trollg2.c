//Coded by Bane//
#include <std.h>
inherit "/d/laerad/mon/wander/tgwander.c";
void create()
{
    ::create();
    set_id(({ "troll", "guard", "troll guard" }));
    set_name("troll guard");
    set_short("A Troll guard");
    set_long(
        "This is a rather large troll guard.  He is dressed in a hide " +
        "cloth.  His skin is a putred green and his eyes bulge out of his " +
        "head.  He stands over 7 feet tall and looks extremely fierce."
        );
    set_body_type("human");
    set_race("troll");
    set_gender("male");
    set_size(2);
    set_hd(12, 14);
    set_hp(110);
    set_overall_ac(-3);
    set_resistance_percent("fire", -50);
    set_resistance_percent("acid", -50);
    set_exp(0);
    set_stats("strength", 20);
    set_stats("constitution", 24);
    set_property("swarm", 1);
    add_money("gold", random(200) + 300);
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
    if (!objectp(TO)) {
        return;
    }
    if (query_hp() < 110) {
        add_hp(2);
        return;
    }
}

void die(object targ)
{
    if (query_hp() < -15) {
        query_current_attacker()->add_exp(2000);
        return ::die(targ);
    }
    tell_room(ETO, "%^RED%^Troll guard drops dead before you.");
    new("/d/laerad/mon/obj/tcorpse1")->move(ETO);
    remove();
}
