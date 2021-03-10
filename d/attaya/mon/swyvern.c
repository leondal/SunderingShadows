
#include <std.h>
inherit WEAPONLESS;

create()
{
    ::create();
    set_name("wyvern");
    set_id(({ "silver wyvern", "wyvern" }));
    set_short("Silver wyvern");
    set_long(
        "The wyvern is a large dragon-like creature that has been specially bred by the Kinnesaruda as guardians.  Lacking the intelligence of most dragons, and bred with an animalistic desire to hunt and kill, only the undead are safe from these menaces.\n The Silver wyvern has a tough series of metal-like scales protecting it."
        );
    set_gender("male");
    set_race("wyvern");
    set_body_type("dragon");
    set_property("swarm", 1);
    set_property("full attacks", 1);
    set_hd(26, 0);
    set_overall_ac(-12);
    set_size(4);
    set_wielding_limbs(({ "left front claw", "right rear claw" }));
    set_attacks_num(2);
    set_attack_limbs(({ "left wing", "right wing", "tail", "left rear claw", "right rear claw", "left front claw", "right front claw", "head" }));
    set_property("no rush", 1);
    set_base_damage_type("slashing");
    set_damage(1, 8);
    set_moving(1);
    set_speed(30);
    set_stats("strength", 19);
    set_stats("intelligence", 6);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 5);
    set_class("fighter");
    set("aggressive", 22);
    set_alignment(4);
    set_hp(400);
    set_exp(5000);
    set_funcs(({ "fire" }));
    set_func_chance(50);
    set_wielding_limbs(({ "left hand", "right hand" }));
    add_money("gold", 20 + random(540));
}

void init()
{
    ::init();
// added ::init() to fix/prevent bugs & changed wizardp to check true invis 2/23/03 *Styx*
    if (TP->query_invis() && !TP->query_true_invis() && !TP->is_monster()) {
        tell_room(ETO, "%^RED%^The wyvern senses your movement and attacks!");
        TP->set_invis();
        kill_ob(TP, 1);
    }
    if (TP->query_stats("charisma") < 25) {
        kill_ob(TP, 1);
    }
}

void fire(object targ)
{
    if (!targ) {
        return 0;
    }
    if (random(25) > targ->query_stats("charisma")) {
        tell_room(environment(targ), "%^BOLD%^%^BLUE%^The silver wyvern glows with a mystic blue light.", targ);
        tell_room(environment(targ), "%^BOLD%^%^BLUE%^A glowing blue sphere of energy flies from the wyvern and blasts " + targ->query_cap_name() + "!", targ);
        tell_object(targ, "%^BOLD%^%^BLUE%^The silver wyvern blasts you with a sphere of blue light doing massive damage!");
        set_property("magic", 1);
        targ->do_damage("torso", random(30) + 50);
        set_property("magic", -1);
        return 1;
    } else {
        tell_object(targ, "%^BOLD%^%^BLUE%^The silver wyvern draws back its head and lets loose a tremendous scream and you shudder!");
    }
}
