
#include <std.h>
inherit MONSTER;

create()
{
    ::create();
    set_name("wyvern");
    set_id(({ "arctic wyvern", "wyvern" }));
    set_short("Arctic wyvern");
    set_long(
        "The wyvern is a large dragon-like creature that has been specially bred by the Kinnesaruda as guardians.  Lacking the intelligence of most dragons, and bred with an animalistic desire to hunt and kill, only the undead are safe from these menaces.\n The arctic wyvern is a very strange creature and appears to be made completely out of ice!"
        );
    set_gender("male");
    set_race("wyvern");
    set_body_type("dragon");
    set_property("swarm", 1);
    set_property("full attacks", 1);
    set_hd(36, 0);
    set_overall_ac(-8);
    set_size(4);
    set_moving(1);
    set_property("no rush", 1);
    set_speed(40);
    set_stats("strength", 19);
    set_stats("intelligence", 6);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 5);
    set_class("fighter");
    set("aggressive", 22);
    set_alignment(4);
    set_hp(300);
    set_exp(12500);
    set_funcs(({ "fire" }));
    set_func_chance(50);
    set_wielding_limbs(({ "left hand", "right hand" }));
    set_base_damage_type("slashing");
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
}

void fire(object targ)
{
    if (!targ) {
        return 0;
    }
    if (random(25) > targ->query_stats("wisdom")) {
        tell_room(environment(targ), "%^BOLD%^%^CYAN%^The arctic wyvern draws back its head and lets loose a tremendous breath of ice that freezes " + targ->query_cap_name() + "!", targ);
        tell_object(targ, "%^BOLD%^%^RED%^The arctic wyvern draws back its head and lets loose a tremendous breath of ice that freezes you!");
        set_property("magic", 1);
        targ->do_damage("torso", random(15) + 15);
        set_property("magic", -1);
        targ->set_paralyzed(random(30) + 30, "You are frozen solid!");
        return 1;
    } else {
        tell_object(targ, "%^BOLD%^%^CYAN%^The arctic wyvern draws back its head and lets loose a tremendous breath of ice, but you are able to dodge out of the way!");
        tell_room(environment(targ), "%^CYAN%^The arctic wyvern draws back its head and lets loose a tremendous breath of ice at " + targ->query_cap_name() + " but they dodge out of the way", targ);
    }
}
