#include <std.h>
#include "/d/islands/dallyh/fways.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("amazon hunter");
    set_id(({"amazon","hunter","amazon hunter", "woman", "muscular woman"}));
    set_short("%^BOLD%^%^GREEN%^A muscular woman with "+
    "%^BOLD%^%^BLACK%^dark hair%^BOLD%^%^GREEN%^ and %^BOLD%^%^BLACK%^dark eyes%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This woman stand over six feet tall. She has long "+
    "dark hair that comes down to nearly the middle of her back, it is messy and "+
    "unkept, flowing wildly around her roundish face. She has dark eyes, which reflect "+
    "an immense intelligent and a profound concern, though you are unable to determine the "+
    "exact cause of her concern. The visible portions of her body are muscular and well toned. "+
    "She has long lean legs which serve to make her look quite agile. She is almost difficult "+
    "to focus on, as if something is off or wrong about her. However, you are unsure of what it "+
    "is.%^RESET%^");

    set_gender("female");
    set_level(26);
    set_body_type("human");
    set_class("fighter");
    set_alignment(9);
    set_size(2);
    add_search_path("/cmds/fighter");
    set_hd(26,2);
    set_overall_ac(-5);
    set_stats("strength",21);
    set_property("full attacks", 1);
    set_hp(455 + random(175));
    set_moving( 1 );
    set_speed(50);
    set("aggressive","aggfunc");
    set_race("human");
    switch(random(3))
    {
        case 0..1:

            switch(random(6))
            {
                case 0..3: new( FOPATH "spear.c")->move(TO);
                    command("wield spear");
                    break;
                case 4: "/d/common/daemon/randgear_d"->arm_me(TO,"polearm",40,3);
                    break;
                case 5: "/d/common/daemon/randgear_d"->arm_me(TO,"tool",40,3);
                    break;
            }
            set_monster_feats(({
                "toughness",
                "improved toughness",
                "damage resistance",
                "improved damage resistance"
            }));
            break;

        case 2:
        {
            object bow;
            set_monster_feats(({
                "point blank shot",
                "manyshot",
                "deadeye",
                "preciseshot",
                "shot on the run"
            }));
            bow = new("/d/islands/dallyh/forest/obj/fbow");
            bow->move(TO);
            command("wield bow");
            if (random(20)) {
                bow->set_property("monster weapon", 1);
            }
            new("/d/common/obj/lrweapon/larrows")->move(TO);
        }
            break;
    }
    new(FOPATH "panther.c")->move(TO);
    command("wear skin");
    set_mob_magic_resistance("low");
    set_stats("strength", 22);
    set_stats("dexterity", 19);
    set_stats("intelligence", 10);
    set_stats("wisdom", 10);
    set_stats("charisma", 10);
    set_stats("constitution", 25);
    set_new_exp(26, "high");
    set_nogo(({DDOCK, FRPATH"road1"}));
}

int aggfunc()
{
    int notifyTime;
    if(!objectp(TP)) return 0;
    if(TP->query_true_invis())  return 1;
    if(userp(TP))
    {
        if(objectp(ETO))
        {
            notifyTime = (int)ETO->query_property("notifiedTime");
            if(time() > notifyTime)
            {
                force_me("say you must seek out the village and heed the call that awaits you!");
                ETO->remove_property("notifiedTime");
                ETO->set_property("notifiedTime", time() + 300);
                return 1;
            }
        }
    }
    if(TP->id("dallyhallyevil"))
    {
        force_me("say you will NOT corrupt this forest!");
        force_me("kill "+TPQN);
    }
    return 1;
}

void init()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(TP)) return;
    if(TP->id("dallyhallyevil"))
    {
        force_me("say you will NOT corrupt this forest!");
        force_me("kill "+TPQN);
    }
}

void die(object ob)
{
    if(objectp(TO))
    {
        if(objectp(ETO))
        {
            all_inventory(TO)->move(ETO);
            tell_room(ETO, TO->query_short()+"%^BOLD%^%^WHITE%^ collapses into a puff of sm%^RESET%^%^WHITE%^o"+
            "%^BOLD%^k%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^!%^RESET%^");
        }
        TO->move("/d/shadowgate/void");
        if(objectp(TO)) TO->remove();
    }
    //::die(ob);
}
