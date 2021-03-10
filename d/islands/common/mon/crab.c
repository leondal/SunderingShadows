#include <std.h>
inherit WEAPONLESS;
void create()
{
    ::create();
    set_name("sand crab");
    set_id(({ "sand crab", "crab", "giant" }));
    set_short("Giant sand crab");
    set_long("
    Crabs of this size are common on distant islands.  They have no natural predators out of the water, but the crab's tough shell shows signs of damage from some oceanic monstrosity.
");
    set_race("crab");
    set_hd(25, 10);
    set_level(25);
    set_size(3);
    set_overall_ac(-8);
    set_class("fighter");
    set_guild_level("fighter", 20);
    set_max_hp(210);
    set_hp(410);
    set_wielding_limbs(({ "right claw", "left claw" }));
    add_limb("right claw", "right claw", 96, 1, 4);
    add_limb("left claw", "left claw", 96, 1, 4);
    set_attacks_num(2);
    set_attack_limbs(({ "left claw", "right claw" }));
    set_base_damage_type("bludgeoning");
    set_damage(2, 6);
    set_body_type("arachnid");
    set_property("swarm", 1);
    set_property("no bump", 1);
    set_stats("strength", 16);
    set_stats("dexterity", 16);
    set_stats("constitution", 17);
    set("aggressive", "aggfunc");
    set_mob_magic_resistance("average");
    set_exp(6000);
    set_alignment(5);
}

void die(object ob)
{
    message("environment",
            "%^BOLD%^%^MAGENTA%^Giant sand crab falls on its side, then rolls onto its back and curls up its legs."
            , environment(TO));
    :: die(ob);
}

int aggfunc()
{
    TP->kill_ob(TO, 0);
    force_me("emote raises its claws and scurries towards you!");
}
