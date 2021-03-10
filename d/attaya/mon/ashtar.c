#include <std.h>
inherit WEAPONLESS;
void create()
{
    ::create();
    set_name("ashtar");
    set_id(({ "ashtar", "warrior", "supreme warrior" }));
    set_short("Ashtar the Supreme Warrior");
    set_long(
        "Ashtar is the leader of the undead skeletal phalanxs and warriors that guard Attaya.  He is the first guardian of Intruder. He wears a black shroud and a horned helmet.  Ashtar stands over nine feet tall!  His upper body is protected by a thick armor with two living metal limbs attached to it! Numerous skulls hang from various parts of Ashtar's armor."
        );
    set_race("undead");
    set_hd(45, 10);
    set_level(45);
    set_gender("male");
    set_size(3);
    set_overall_ac(-24);
    set_class("fighter");
    set_guild_level("fighter", 45);
    set_max_hp(2420);
    set_hp(2420);
    set_body_type("human");
    set_wielding_limbs(({ "right hand", "left hand" }));
    add_limb("left metal appendage", "left metal appendage", 96, 1, 4);
    add_limb("right metal appendage", "right metal appendage", 96, 1, 4);
    add_limb("horned helmet", "horned helmet", 96, 1, 4);
    set_attacks_num(6);
    set_attack_limbs(({ "left metal appendage", "right metal appendage", "horned helmet", "left hand", "right hand", "left foot", "right foot" }));
    set_base_damage_type("bludgeoning");
    set_damage(2, 10);
    set_property("swarm", 1);
    set_property("no bump", 1);
    set_property("no death", 1);
    set_property("magic", 1);
    set_stats("strength", 22);
    set_stats("dexterity", 16);
    set_stats("constitution", 17);
    set("aggressive", "aggfunc");
    set_mob_magic_resistance("low");
    set_exp(50000);
    set_alignment(9);
    new("/d/attaya/obj/shroud.c")->move(this_object());
    command("wear shroud");
    new("/d/attaya/obj/bhelm.c")->move(this_object());
    command("wear helmet");
    set_resistance("negative energy", 20);
    set_resistance("positive energy", -20);
}

void die(object ob)
{
    message("environment",
            "%^BOLD%^%^MAGENTA%^Ashtar falls to his knees and grabs his throat.\n"
            , environment(TO));
    force_me("say How could this have happened...  Destiny...  You cannot defeat me...  This is NOT the way it was supposed to happen...  DESTINY!");
    force_me("storm");
    :: die(ob);
}

int aggfunc()
{
    string mrace = TP->query_race();
    if (mrace == "undead") {
        force_me("grin");
        return 1;
    } else {
        if (wizardp(TP)) {
            return 1;
        }
        TP->kill_ob(TO, 0);
        force_me("say %^RED%^I'll show you no mercy.  I SHALL DESTROY YOU!");
        force_me("storm");
    }
}

void set_paralyzed(int time, string message)
{
    return 1;
}
