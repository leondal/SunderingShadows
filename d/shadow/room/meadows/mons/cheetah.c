#include <std.h>
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("cheetah");
    set_short("A quick cheetah");
    set_id(({ "cheetah", "quick cheetah", "monster" }));
    set_long(
        "The cheetah is agile and full of speed and grace. Her %^ORANGE%^amber%^CYAN%^" +
        " eyes stare at you, a little bit hungrily. Black spots cover her golden" +
        " fur, and white hair covers her chest. She has dark lines trailing" +
        " downwards from the edges of her eyes, giving her an almost sorrowful" +
        " look. Her ears are constantly twitching, alert for any sounds. She is" +
        " probably here hunting for food for her cubs, wherever they may be."
        );
    set_hd(12, 5);
    set_race("cat");
    set_gender("female");
    set_body_type("quadruped");
    set("aggressive", 15);
    set_property("swarm", 1);
    //set_level(14);
    //set_class("fighter");
    //set_mlevel("fighter",14);
    set_hp(random(25) + 80);
    set_new_exp(6, "normal");
    set_damage(1, 4);
    set_stats("strength", 18);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    add_limb("left paw", "left hand", 0, 0, 0);
    add_limb("right paw", "right hand", 0, 0, 0);
    add_limb("mouth", "head", 0, 0, 0);
    set_attack_limbs(({ "left paw", "right paw", "mouth" }));
    set_hit_funcs((["mouth" : (: TO, "bite" :) ]));
    set_overall_ac(4);
    set_alignment(5);
    set_emotes(4, ({
        "The cheetah crouches low to the ground, ready to pounce.",
        "The cheetah listens intently for any sounds.",
        "The cheetah slinks across the ground.",
        "The cheetah licks her whiskers.",
    }), 0);
    set_emotes(4, ({
        "The cheetah roars in anger.",
        "The cheetah scratches you!",
    }), 1);
    set_funcs(({ "dash" }));
    set_func_chance(5);
    set_max_level(12);
    if (!random(15)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("fur");
        ob->move(TO);
    }
}

void dash(object targ)
{
    tell_object(targ, "%^YELLOW%^The cheetah moves with incredible speed," +
                " knocking you over!");
    tell_room(ETO, "%^YELLOW%^The cheetah moves with incredible speed, knocking" +
              " " + targ->query_cap_name() + " over!", targ);
    targ->set_tripped(2, "You're still recovering from being knocked down.");
    return 1;
}
