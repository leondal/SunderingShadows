//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
void create()
{
    ::create();
    set_id(({ "troll", "scout", "troll scout" }));
    set_name("troll scout");
    set_short("A Troll scout");
    set_long(
        "This is a nimble troll scout.  He is covered in camoflage " +
        "clothes.  His skin is a putred green and his eyes bulge out of his " +
        "head.  He stands about 7 feet tall and moves like lightning."
        );
    set_body_type("human");
    set_race("troll");
    set_gender("male");
    set_size(2);
    set_hd(11, 12);
    set_hp(55);
    set_overall_ac(-2);
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
    set_damage(1, 6);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
}

void init()
{
    ::init();
    if (wizardp(TP)) {
        return 1;
    }
    if (TP->query_invis()) {
        return 1;
    }
    if ((string)TP->query_race() == "human" || (string)TP->query_race() == "elf" || (string)TP->query_race() == "half-elf" || (string)TP->query_race() == "dwarf" || (string)TP->query_race() == "gnome" || (string)TP->query_race() == "halfling") {
        if (interactive(TP)) {
            force_me("say ARGH! Die scum!");
        }
        force_me("kill " + TPQN);
        return 1;
    }
    if (interactive(TP)) {
        force_me("nod");
    }
    return 1;
}

void heart_beat()
{
    ::heart_beat();
    if (query_hp() < 100) {
        add_hp(2);
        return;
    }
}

void die(object ob)
{
    if (query_hp() < -15) {
        if (objectp(query_current_attacker())) {
            query_current_attacker()->add_exp(2500);
        }
        return ::die(ob);
    }
    tell_room(ETO, "%^RED%^Troll scout drops dead before you.");
    new("/d/laerad/mon/obj/tcorpses")->move(ETO);
    remove();
}
