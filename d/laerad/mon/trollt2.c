//Coded by Bane//
//Used specifically for the invasions into Asgard, don't change.
#include <std.h>

inherit "/d/laerad/mon/wander/ttwander.c";
void move_me();
int num;

void create()
{
    ::create();
    set_id(({ "troll", "thug", "troll thug" }));
    set_name("troll thug");
    set_short("A Troll thug");
    set_long(
        "This is a vicious troll thug.  He is dressed in heavy leather clothing, " +
        "and covered in spiked chains.  His skin is a putrid green, his hair " +
        "a tangled mess.  He stands nearly 8 feet tall and wanders the forest " +
        "searching for any stray humans or Asgardians to slaughter."
        );
    set_body_type("human");
    set_race("troll");
    set_gender("male");
    set_size(2);
    set_hd(15, 5);
    set_hp(125);
    set_overall_ac(-4);
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
    move_me();
    num = random(5) + 2;
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
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
    if (!objectp(TO)) {
        return;
    }
    if (query_hp() < 125) {
        add_hp(2);
        return;
    }
}

void die(object targ)
{
    if (query_hp() < -15) {
        query_current_attacker()->add_exp(3500);
        return ::die(targ);
    }
    tell_room(ETO, "%^RED%^Troll thug drops dead before you.");
    new("/d/laerad/mon/obj/tcorpset")->move(ETO);
    remove();
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
