#include <std.h>
#include "../ruins.h"
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("spectre");
    set_short("A haunting spectre");
    set_id(({ "spectre", "haunting spectre", "monster" }));
    set_long(
        "The spectre is almost see-through in appearance, and is hovering just" +
        " above the ground. A long robe of pale grey covers all but his head" +
        " and hands. His hands are more like claws than anything else, with long," +
        " sharp fingernails on them. His face is twisted by a mask of anger, rage" +
        " and pain. Flowing white hair trails down his back, ever blowing in a" +
        " non-existant wind."
        );
    set_gender("male");
    set_race("spectre");
    set_body_type("humanoid");
    set_property("undead", 1);
    set_hd(20, 5);
    set_max_hp(250 + random(40));
    set_hp(query_max_hp());
    set_alignment(3);
    set_property("weapon resistance", 1);
    set_mob_magic_resistance("average");
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_level(20);
    set_overall_ac(-13);
    set_exp(7000);
    set_max_level(25);
    set_stats("strength", 20);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(2);
    set_damage(3, 4);
    set_property("swarm", 1);
    set("aggressive", 25);
    set_funcs(({ "drain" }));
    set_func_chance(30);
    set_property("magic", 1);
    set_resistance("negative energy", 10);
    set_resistance("positive energy", -10);
}

void drain(object targ)
{
    int i, j;

    if (!"/daemon/saving_d"->fort_save(targ, -20)) {
        tell_object(targ, "%^BOLD%^%^CYAN%^The chilling touch of the spectre" +
                    " freezes your flesh, leaving you paralyzed!");
        tell_room(ETO, "%^BOLD%^%^CYAN%^The spectre reaches out and touches" +
                  " " + targ->query_cap_name() + ", leaving " + targ->query_objective() + " paralyzed!", targ);
        targ->set_paralyzed(roll_dice(1, 4) * 8, "You are frozen from the touch of the spectre!");
        targ->do_damage("torso", random(5) + 6);
        return 1;
    }else {
        tell_object(targ, "%^BOLD%^%^BLUE%^The spectre's touch burns your flesh" +
                    " it is so cold, but you manage to break away from its hold.");
        tell_room(ETO, "%^BOLD%^%^BLUE%^The spectre reaches out and touches" +
                  " " + targ->query_cap_name() + ", but " + targ->query_subjective() + " manages" +
                  " to break away.", targ);
        targ->do_damage("torso", random(4) + 3);
        return 1;
    }
}
