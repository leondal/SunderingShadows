//Coded by Bane//
// This one is used specifically for the invasions into Asgard!

#include <std.h>

inherit "/d/laerad/mon/wander/ttwander.c";

void move_me();
object num;

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
        "prismatic spray",
    }));
    set_spell_chance(75);
    move_me();
    num = random(5) + 2;
}

void init()
{
    string race;
    ::init();
    race = (string)TP->query_race();
    if (wizardp(TP) || TP->query_true_invis()) {
        return 1;
    }
    if (race == "human" || race == "elf" || race == "half-elf" || race == "dwarf" || race == "gnome" || race == "halfling") {
        if (interactive(TP)) {
            force_me("say ARGH! Die scum!");
        }
        force_me("kill " + TPQCN);
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
    if (query_hp() < 125) {
        add_hp(2);
        return;
    }
}

void die(object targ)
{
    if (query_hp() < -15) {
        query_current_attacker()->add_exp(6500);
        return ::die(targ);
    }
    tell_room(ETO, "%^RED%^Troll war mage drops dead before you.");
    new("/d/laerad/mon/obj/tcorpsem")->move(ETO);
    remove();
}

void reset()
{
    object ob;
    ::reset();
    if (!present("scroll")) {
        ob = new("/d/magic/scroll");
        ob->set_spell(8);
        ob->move(TO);
    }
}

void move_me()
{
    force_me("north");
    call_out("go_north", 5, TP);
}

void go_north()
{
    force_me("north");
    call_out("go_north1", num, TP);
}

void go_north1()
{
    force_me("north");
    call_out("go_north2", num, TP);
}

void go_north2()
{
    force_me("north");
    call_out("go_north3", num, TP);
}

void go_north3()
{
    force_me("north");
    call_out("go_north4", num, TP);
}

void go_north4()
{
    force_me("north");
    call_out("go_north5", num, TP);
}

void go_north5()
{
    force_me("north");
    call_out("go_north6", num, TP);
}

void go_north6()
{
    force_me("north");
    call_out("go_north7", num, TP);
}

void go_north7()
{
    force_me("west");
    call_out("go_sw", num, TP);
}

void go_sw()
{
    force_me("southwest");
    call_out("go_west", num, TP);
}

void go_west()
{
    force_me("west");
    call_out("go_west2", num, TP);
}

void go_west2()
{
    force_me("west");
    call_out("go_west3", num, TP);
}

void go_west3()
{
    force_me("west");
    call_out("go_west4", num, TP);
}

void go_west4()
{
    force_me("west");
}
