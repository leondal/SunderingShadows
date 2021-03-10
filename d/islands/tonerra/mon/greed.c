//greed.c

#include <std.h>

#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void create()
{
    ::create();

    set_name("Greedy possessor");
    set_id(({ "greed", "possessor", "Greedy possessor", "greedy" }));
    set_short("Greedy possessor");
    set_long("This etherial being has lept from the tapestry hanging on the wall. He seeks to possess you now. It's sole motive in life is greed. He stands before you in a great rage of insecurity and longing.");
    set_hd(35, 8);
    set_hp(540);

    set_attacks_num(4);
    set_damage(2, 5);
    set_stats("strength", 18);
    set_mob_magic_resistance("average");
    set_property("weapon resistance", 2);

    set_base_damage_type("bludgeoning");

    set_overall_ac(-14);
    set_attack_limbs(({ "grasping right hand", "grasping left hand" }));
    set_hit_funcs((["grasping right hand" : (: TO, "pound" :), "grasping left hand" : (: TO, "pound" :)]));
    set_exp(35000);
    set_max_level(36);
    set_body_type("human");
    set_gender("male");
    set_race("etherial emotion");
    set("aggressive", 24);
}

int pound(object rag)
{
    if (!objectp(rag)) {
        return random(4);
    }

    if (random(7)) {
        return 0;
    }

    if (rag->query_paralyzed()) {
        return 5;
    }
    tell_object(rag, "%^BLUE%^The possessor grasps your heart and you feel a longing for things that you have never felt. It paralyzes your mind.\n");
    tell_room(ETO, "%^BLUE%^The possessor seems to reach into " + rag->query_cap_name() + "'s chest and grasp " + rag->query_possessive() + " heart, paralyzing " + rag->query_objective() + ".", rag);


    rag->set_paralyzed(16 + random(24), "You are overcome with greed.");
    return random(5);
}

void die(object ob)
{
    object ob2;
    tell_room(ETO, "%^RED%^As the death blow is dealt the etherial emotion gels into a single shiny stone.");

    ob = new("/std/Object");
    ob->set_name("Gelled greed");
    ob->set_short("%^CYAN%^Gelled Greed");
    ob->set_long("This small crystal is a translucent stone evidentally the etherial emotion of greed captured.");
    ob->set_id(({ "gel", "greed", "gelled greed" }));
    ob->move(ETO);
    remove();
}
