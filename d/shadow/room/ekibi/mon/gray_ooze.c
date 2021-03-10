//gray_ooze.c - Mob for low level underdark area
//by Circe 3/11/05
#include <std.h>
#include "../ekibi.h"

inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("gray ooze");
    set_short("a harmless puddle of water");
    set_id(({ "water", "puddle", "puddle of water", "water puddle", "ooze", "gray ooze" }));
    set_long("What looks at first like a harmless puddle of water " +
             "on the cavern floor actually appears to be moving!  It shifts " +
             "forms slowly, changing thickness and length.  It is a moist " +
             "shade of gray that perfectly matches the shadows of the " +
             "cavern floor.");
    set_gender("neuter");
    set_race("ooze");
    add_limb("body", "body", 80, 0, 3);
    set_size(1);
    set_alignment(5);
    set_hd(7, 5);
    set("aggressive", 16);
    set_property("swarm", 1);
    set_class("fighter");
    set_mlevel("fighter", 7);
    set_hp(random(10) + 60);
    set_overall_ac(4);
    set_stats("strength", 12);
    set_damage(1, 4);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "body" }));
    set_exp(200);
    set_emotes(2, ({
        "The puddle ripples with an unfelt breeze.",
        "The puddle seems to expand, then contract on its own."
    }), 0);
    set_emotes(4, ({
        "The ooze forms pseudopods and slams into you!"
    }), 1);
    set_max_level(10);
    set_funcs(({ "acid" }));
    set_func_chance(5);
}

void die(object obj)
{
    if (!random(4)) {
        tell_room(ETO, "You catch a glimpse of...something...inside the puddle.");
        "/d/common/daemon/randtreasure_d"->find_stuff(TO, "stuff");
    }
    tell_room(ETO, "The puddle shudders and shakes before losing all form!");
    ::die(obj);
}

void acid(object targ)
{
    string name = targ->query_name();
    tell_object(targ, "%^GREEN%^Acid stings your flesh as the ooze hits you!");
    tell_room(ETO, "" + name + " is burned by acid from the ooze!", targ);
    targ->do_damage(targ->return_target_limb(), random(3) + 6);
    return;
}
