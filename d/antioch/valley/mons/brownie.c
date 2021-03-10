//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit VM_WANDER;

void create()
{
    ::create();
    set_name("brownie");
    set_id(({ "brownie", "monster","fey" }));
    set_short("A peaceful brownie");
    set_long(
        "This is an adorable little brownie. He stands about two" +
        " feet in height and looks very harmless. He almost looks" +
        " like a small elf with his pointy ears and delicate features." +
        " He has brown hair and wide, innocent blue eyes that stare" +
        " back at you. His clothes are rather brightly colored and" +
        " you can't imagine him being able to hide well in them, but" +
        " somehow he manages."
        );
    set_size(1);
    set_race("brownie");
    set_gender("male");
    set_body_type("kender");
    set_hd(25, 2);
    set_max_level(20);
    set_alignment(1);
    set_overall_ac(3);
    set_max_hp(random(25) + 50);
    set_hp(query_max_hp());
    set_level(25);
    set_class("mage");
    set_mlevel("mage", 15);
    set_class("fighter");
    set_mlevel("fighter", 15);
    set_stats("intelligence", 18);
    set_stats("dexterity", 20);
    set_mob_magic_resistance("average");
    set_property("swarm", 1);
    set_property("full attacks", 1);
    new("/d/common/obj/weapon/shortsword")->move(TO);
    command("wield sword");
    set_funcs(({ "confuse" }));
    set_func_chance(60);
//	set_exp(9050);
    set_new_exp(15, "normal");
}

//thief invis\\

void confuse(object targ)
{
    tell_room(ETO, "The brownie begins casting a spell!");
    if (!"/daemon/saving_throw_d.c"->will_save(targ, -14)) {
        tell_object(targ, "%^MAGENTA%^%^BOLD%^The brownie finishes" +
                    " his spell and you suddenly feel very confused.");
        targ->set_paralyzed(100, "%^MAGENTA%^%^BOLD%^You are confused.");
        tell_room(ETO, "%^MAGENTA%^%^BOLD%^As the" +
                  " brownie finishes his spell, " + targ->query_cap_name() + "" +
                  " appears very confused.", targ);
        return 1;
    }else {
        tell_object(targ, "%^YELLOW%^You successfully resist the" +
                    " brownie's spell!");
        tell_room(ETO, "%^YELLOW%^" + targ->query_cap_name() + "" +
                  " successfully resists the brownie's spell.", targ);
        return 1;
    }
}
