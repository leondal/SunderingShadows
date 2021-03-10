//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit VM_WANDER;

void create()
{
    ::create();
    set_name("atomie");
    set_id(({ "monster", "atomie", "sprite", "faerie", "fairy","fey" }));
    set_short("An energetic atomie");
    set_long(
        "This is a lively little atomie, he is just under one foot" +
        " tall but can't seem to hold still for a moment. He has" +
        " four small, very beautiful wings, much like those of a" +
        " dragonfly. His features are elven and though his complexion" +
        " is rather pale, it has a hint of green to it. The clothing" +
        " this little atomie wears is a mix of bright greens and" +
        " blues that somehow blend perfectly with the woodland" +
        " surroundings."
        );
    set_size(1);
    set_body_type("kender");
    set_race("atomie");
    set_gender("male");
    set_hd(15, 2);
    set_max_level(20);
    set_wielding_limbs(({ "right hand", "left hand" }));
    set_alignment(8);
    set_overall_ac(4);
    set_max_hp(random(50) + 50);
    set_hp(query_max_hp());
    set_property("swarm", 1);
    set_class("fighter");
    set_mlevel("fighter", 15);
    set_level(15);
//	set_exp(4150);
    set_new_exp(15, "normal");
    add_money("electrum", random(20));
    set_mob_magic_resistance("average");
    if (!random(4)) {
        new(OBJ + "sspear")->move(TO);
        command("wield spear");
    }else {
        new(OBJ + "tlongsword")->move(TO);
        command("wield sword");
    }
    set_funcs(({ "dive" }));
    set_func_chance(30);
}

//invis as spell\\

void dive(object targ)
{
    int roll, dex;
    roll = random(20);
    dex = targ->query_stats("dexterity");

    if (roll > dex) {
        tell_object(targ, "%^BOLD%^%^CYAN%^The atomie swoops down" +
                    " into a dive and strikes you!");
        tell_room(environment(ETO), "%^BOLD%^%^CYAN%^The atomie" +
                  " swoops down and dives at " + targ->query_cap_name() + "," +
                  " striking " + targ->query_objective() + "!", targ);
        targ->do_damage("torso", random(8) + 6);
    }else {
        tell_object(targ, "%^BOLD%^%^CYAN%^The atomie dives at you," +
                    " but you manage to dodge to the side.");
        tell_room(environment(ETO), "%^BOLD%^%^CYAN%^The atomie" +
                  " dives at " + targ->query_cap_name() + " but " + targ->query_subjective() + "" +
                  " dodges out of the way.", targ);
    }
}
