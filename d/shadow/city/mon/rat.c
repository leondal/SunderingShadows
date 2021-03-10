#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("dire rat");
    set_id(({ "rat", "dire rat", "rodent" }));
    set_short("%^RESET%^%^GREEN%^muck-cover%^RED%^e%^GREEN%^d %^ORANGE%^dire rat%^WHITE%^");
    set_long("%^RESET%^%^ORANGE%^The size of a small dog, this " +
             "%^GREEN%^feral rat %^ORANGE%^is aggressive and clearly has a taste for blood. " +
             "It is covered in m%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^tted, " +
             "coar%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^e f%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^r " +
             "and smells like %^BOLD%^%^RED%^blood %^RESET%^%^ORANGE%^and " +
             "%^BOLD%^%^RED%^feces%^RESET%^%^ORANGE%^. The ugly rats run rampant throughout " +
             "the sewers, always sniffing out their next meal.\n%^WHITE%^");
    set_gender("male");
    set_race("rat");
    set_body_type("quadruped");
    set_alignment(2);
    set_size(2);
    set_hd(12, 5);
    set_stats("strength", 16);
    set_stats("dexterity", 16);
    set_hp(90 + random(15));
    set_max_hp(query_hp());
    set_new_exp(10, "normal");
    set_base_damage_type("piercing", "biting");
    set_base_damage_type("piercing", "biting");
    set_attack_limbs(({ "mouth" }));
    set_hit_funcs((["mouth" : (: TO, "bite" :)]));
    set_property("swarm", 1);
    set_damage(5, 2);
    set_moving(10);
    set_speed(75);
    set_funcs(({ "rake" }));
    set_func_chance(50);
    set_overall_ac(0);
    set_nogo(({ ROOMS "chamber" }));
}

void bite(object targ)
{
    if (!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death")) {
        tell_object(targ, "%^RESET%^%^GREEN%^%^BOLD%^%^RED%^The %^RESET%^%^ORANGE%^rat %^BOLD%^%^RED%^sinks " +
                    "its %^GREEN%^fil%^RESET%^%^ORANGE%^t%^GREEN%^h%^BOLD%^y%^RED%^, " +
                    "%^BLACK%^d%^RESET%^%^RED%^i%^ORANGE%^s%^BOLD%^%^BLACK%^eas%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d " +
                    "%^RED%^teeth into your flesh!%^RESET%^%^RESET%^");
        tell_room(ETO, "%^RESET%^%^GREEN%^The rat sinks its %^BOLD%^%^BLACK%^filthy teeth%^RESET%^%^GREEN%^ into " + targ->query_cap_name() + "!%^RESET%^", targ);
        targ->set_paralyzed(20, "%^BOLD%^%^BLACK%^You feel lethargic and sick!%^RESET%^");
        return 1;
    }
    "/std/diseases/diseases/filth_fever"->infect(targ, query_level());
    tell_object(targ, "%^RESET%^%^ORANGE%^The rat lunges, its %^RESET%^sharp teeth%^ORANGE%^ barely grazing your skin.%^RESET%^");
    tell_room(ETO, "%^RED%^The rat lunges, trying to sink its teeth into " + targ->query_cap_name() + "!%^RESET%^", targ);
    return 1;
}

void rake(object targ)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }
    tell_object(targ, "%^RESET%^%^ORANGE%^The rat %^BOLD%^%^RED%^rakes " +
                "%^RESET%^%^ORANGE%^you with its %^WHITE%^sharp claws%^ORANGE%^, " +
                "digging deep!%^RESET%^");
    tell_room(ETO, "%^RESET%^%^ORANGE%^The rat " +
              "%^BOLD%^%^RED%^rakes " + targ->QCN + " %^RESET%^%^ORANGE%^with its %^WHITE%^sharp " +
              "claws%^ORANGE%^, digging deep!%^RESET%^", targ);
    targ->do_damage("torso", roll_dice(5, 3));
    return 1;
}
