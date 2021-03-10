#include <std.h>
#include "../meadow.h"
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("antelope");
    set_short("A graceful antelope");
    set_id(({ "monster", "antelope", "graceful antelope" }));
    set_long(
        "This is a young male antelope with a small pair of antlers on the" +
        " top of his head. He is slender and well muscled with a shiny coat" +
        " that is a light brown with white spots. His hooves are a solid" +
        " black and he is always ready to dash away if he senses danger."
        );
    set_hd(12, 5);
    set_gender("male");
    set_race("antelope");
    set_size(2);
    set_body_type("quadruped");
    set("aggressive", 12);
    set_property("swarm", 1);
    //set_level(12);
    //set_class("fighter");
    //set_mlevel("fighter",12);
    set_stats("strength", 16);
    set_hp(random(20) + 80);
    set_new_exp(6, "normal");
    set_overall_ac(4);
    set_alignment(5);
    add_limb("right hoof", "right forepaw", 0, 0, 0);
    add_limb("left hoof", "left forepaw", 0, 0, 0);
    set_damage(1, 4);
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({ "right hoof", "left hoof" }));
    set_emotes(2, ({
        "The antelope prances about in agitation.",
        "The antelope nibbles on some grass.",
        "The antelope rubs his antlers against the ground.",
        "The antelope suddenly stills and slowly looks about.",
        "The antelope sniffs the air for signs of danger.",
    }), 0);
    set_funcs(({ "rake" }));
    set_func_chance(30);
    set_max_level(12);
    if (!random(15)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("fur");
        ob->move(TO);
    }
}

void rake(object targ)
{
    int dex, roll;
    dex = targ->query_stats("dexterity");
    roll = random(20);
    if (roll > dex) {
        tell_object(targ, "%^ORANGE%^The antelope rakes you with his antlers!");
        tell_room(ETO, "%^ORANGE%^The antelope rakes " + targ->query_cap_name() + "" +
                  " with his antlers.", targ);
        targ->do_damage("torso", random(5) + 10);
        return 1;
    }
    tell_object(targ, "The antelope tries to rake you with his antlers but" +
                " you manage to dodge.");
    return 1;
}

void die(object obj)
{
    if (!random(2)) {
        new(OBJ + "antlers")->move(TO);
    }
    ::die(obj);
}
