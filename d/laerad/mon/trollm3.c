//Coded by Bane//
// changed to use updated wander inherit *Styx* 7/02

#include <std.h>

inherit "/d/laerad/mon/wander/tgwander.c";
void create()
{
    ::create();
    set_id(({ "troll", "mage", "troll mage", "troll war mage" }));
    set_name("troll war mage");
    set_short("A Troll war mage");
    set_long(
        "This is an evil troll war mage.  He is clothed in a heavy black cloak, " +
        "and covered in spiked chains.  His skin is a putrid green, his hair " +
        "a tangled mess.  He stands only 5 feet tall but his gleaming red eyes " +
        "show that there is more power behind this monster than it seems."
        );
    set_body_type("human");
    set_race("troll");
    set_gender("male");
    set_size(2);
    set_overall_ac(-4);
    set_resistance_percent("fire", -50);
    set_resistance_percent("acid", -50);
    set_stats("strength", 19);
    set_stats("constitution", 24);
    set_property("swarm", 1);
    add_money("gold", random(50) + 10);
    add_money("silver", random(20) + 10);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "right hand", "left hand", "head" }));
    set_attacks_num(3);
    set_damage(1, 4);
    set_guild_level("mage", 18);
    set_hd(18, 14);
    set_hp(160);
    set_exp(0);
    set_spells(({
        "magic missile",
        "lightning bolt",
        "cone of cold",
        "fireball",
        "chain lightning",
        "vampiric touch",
        "powerword stun",
    }));
    set_spell_chance(75);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
}

void init()
{
    string race;
    ::init();
    if (wizardp(TP) || TP->query_true_invis()) {
        return 1;
    }

    if ((string)TP->query_vehicle_type() != "riding animal") {
        race = (string)TP->query_race();
    } else {
        if (objectp(TP->query_current_rider())) {
            if (!call_other((object)TP->query_current_rider(), "query_invis")) {
                race = call_other((object)TP->query_current_rider(), "query_race");
            }
        }
        if (!stringp(race)) {
            race = "horse";
        }
    }
    if ((race == "human" || race == "elf" || race == "half-elf" ||
         race == "dwarf" || race == "gnome" || race == "halfling") &&
        (race != "horse")) {
//       race != "horse") {
        if (interactive(TP)) {
            force_me("say ARGH! Die scum!");
        }
        force_me("kill " + TPQN);
        return 1;
    }
    if (interactive(TP)) {
        force_me("grin");
    }
    return 1;
}

void heart_beat()
{
    ::heart_beat();
    if (query_hp() < 124) {
        add_hp(2);
        return;
    }
}

void die(object targ)
{
    if (query_hp() < -15) {
        query_current_attacker()->add_exp(5500);
        return ::die(targ);
    }
    tell_room(ETO, "%^RED%^Troll war mage drops dead before you.");
    new("/d/laerad/mon/obj/tcorpsem")->move(ETO);
    remove();
}
