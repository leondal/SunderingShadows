#include <std.h>
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("hyena");
    set_short("An ugly looking dog");
    set_id(({ "monster", "hyena", "dog", "ugly dog", "ugly looking dog" }));
    set_long(
        "The hyena is an incredibly ugly specimen. It looks similar to a wild" +
        " dog, but its face is flatter and its coloring is a mottled" +
        " %^ORANGE%^brownish-yellow%^CYAN%^, with black around the ears, face, and paws. It has" +
        " a very stupid look to it as well, with its %^BOLD%^%^MAGENTA%^tongue%^RESET%^%^CYAN%^ usually hanging out" +
        " of its mouth. Its gait is a funny sort of run, and you really have to" +
        " wonder how such a creature survives out here. It must have some trick."
        );
    set_gender("male");
    set_race("hyena");
    set_body_type("quadruped");
    set_alignment(6);
    set_size(1);
    set("aggressive", 12);
    set_property("swarm", 1);
    set_hd(11, 5);
    //set_level(14);
    //set_class("fighter");
    //set_mlevel("fighter",14);
    set_stats("strength", 16);
    set_hp(random(20) + 75);
    set_new_exp(6, "normal");
    set_overall_ac(6);
    add_limb("right claw", "right forepaw", 0, 0, 0);
    add_limb("left claw", "left forepaw", 0, 0, 0);
    add_limb("mouth", "head", 0, 0, 0);
    set_damage(1, 6);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "right claw", "left claw", "mouth" }));
    set_hit_funcs((["mouth" : (: TO, "bite" :)]));
    set_emotes(2, ({
        "The hyena laughs insanely.",
        "The hyena drools as it looks at you.",
        "The hyena sniffs the air.",
        "The hyena paws the ground.",
    }), 0);
    set_max_level(12);
    if (!random(15)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("fur");
        ob->move(TO);
    }
}

int bite(object targ)
{
    if (!random(3)) {
        tell_object(targ, "The hyena bites you viciously, letting blood flow.");
        return random(5) + 3;
    }
    return 1;
}
