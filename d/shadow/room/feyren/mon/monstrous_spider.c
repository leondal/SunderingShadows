#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

int has_eggs;

void create() 
{
    object ob;
    ::create();
    set_name("monstrous spider");
    set_id(({"spider","monstrous spider", "large spider", 
    "dark spider", "dark green spider", "feyrenspidermob"}));
    set_short("%^RESET%^%^GREEN%^Dark green m%^BOLD%^o%^RESET%^%^GREEN%^"+
    "nstr%^BOLD%^ou%^RESET%^%^GREEN%^s spider%^RESET%^");

    set_long("%^RESET%^%^GREEN%^This spider is massive, perhaps "+
    "five feet in diameter, and it looks old. Its eight legs are covered "+
    "in a thick, course dark green fuzz that extends to the rest of its "+
    "body and becomes thicker and coarser. Most of its body is "+
    "a very dark green with flecks of %^BOLD%^grotesque green "+
    "%^RESET%^%^GREEN%^visible on various parts of its body. Its body has many "+
    "scrapes and tears and several of its legs look "+
    "oddly bent as if they never fully healed right. "+
    "Its eyes are a deep %^BOLD%^%^RED%^fiery"+
    "%^RESET%^%^GREEN%^ red. Its speckled black "+
    "mandibles open very wide to reveal two vicious "+
    "fangs. A steady stream of poisonous "+
    "%^BOLD%^goo%^RESET%^%^GREEN%^ drips from them.%^RESET%^");

    set_gender("female");
    set_race("arachnid");
    set_body_type("arachnid");
    set_alignment(5);
    set_size(2);
    set_hd(12,5);
    set("aggressive", 25);
    set_stats("strength",16);
    set_stats("dexterity",16);
    set_hp(120 + random(15));
    set_max_hp(query_hp());
    set_new_exp(12, "normal");
    set_attacks_num(3);
    set_base_damage_type("piercing");
    set_base_damage_type("piercing");
    set_damage(2,4);
    set_moving(10);
    set_speed(75);
    //need to fix poisons so that they work 
    //like we were playing D&D - Saide
    set_property("natural poisoner", 1);
    set_property("natural poison", "medium spider venom");
    set_property("poison chance", 4);
    set_nogo(({OA, FFTR"40"}));
    set_funcs(({"poison_bite", "webbed_n_dead"}));
    set_func_chance(25); 
    set_overall_ac(0);
    has_eggs = random(4);
    if(!random(20)) 
    {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("spiderweb");
        ob->move(TO);
    }
}

void heart_beat()
{	
    string tod; //time of day
    int x = 0, thp;
    object egg;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    //if(sizeof(TO->query_attackers()) > 0) return;
    if(!random(10) && has_eggs == 1) 
    {
        if(!present("eggsac 3", ETO) && !present("spiderling 3", ETO))
        {
            tell_room(ETO, TOQCN +"%^BOLD%^%^YELLOW%^ "+
            "deposits an eggsac into the thick spider "+
            "web!%^RESET%^");
            egg = new(FFOB+"eggsac");
            egg->move(ETO);
        }
    }
    if(ETO->query_property("indoors")) return;
    tod = EVENTS_D->query_time_of_day();
    if(tod == "night" || tod == "twilight") return;
    tell_room(ETO, "%^BOLD%^%^YELLOW%^As the first hint of "+
    "sunlight touches its body, "+TOQCN+"%^BOLD%^%^YELLOW%^"+
    " quickly burrows underground!%^RESET%^");
    TO->remove();
    return;
}


void poison_bite(object targ)
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;

    limb = targ->return_target_limb();

    tell_object(targ, TOQCN+"%^BOLD%^%^GREEN%^"+
    " sinks its fangs deep into your "+limb+", "+
    "pumping poison into the wound!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^GREEN%^ "+
    "sinks its fangs deep into "+targ->QCN+
    "%^BOLD%^%^GREEN%^'s "+limb+"!%^RESET%^", targ);

    tell_object(targ, "%^BOLD%^%^GREEN%^"+
    "You feel woozy as the poison begins to "+
    "take effect!%^RESET%^");

    tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^"+
    " stumbles around crazily for a moment as "+
    "the "+TOQCN+"%^BOLD%^%^GREEN%^ releases "+targ->QP+" "+
    limb+"!%^RESET%^", targ);

    POISON_D->ApplyPoison(targ, "medium spider venom", TO, "injury");
    return;
}

void webbed_n_dead(object targ)
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    tell_object(targ, TOQCN+"%^RESET%^%^GREEN%^"+
    " launches a glob of sticky web at you!%^RESET%^");

    tell_room(ETO, TOQCN+"%^RESET%^%^GREEN%^"+
    " launches a glob of sticky web at "+targ->QCN+
    "%^RESET%^%^GREEN%^!%^RESET%^", targ);

    if(targ->reflex_save(20))
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You "+
        "easily avoid the glob of web!%^RESET%^");

        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ "+
        "easily avoids the glob of web!%^RESET%^", targ);
        return;
    }
    tell_object(targ, "%^BOLD%^%^GREEN%^The glob of "+
    "web splats into you, entangling you with its "+
    "sticky mass!%^RESET%^");
	
    tell_room(ETO, "%^BOLD%^%^GREEN%^The glob "+
    "of web splats into "+targ->QCN+"%^BOLD%^%^GREEN%^ "+
    "entangling "+targ->QO+" with its sticky "+
    "mass!%^RESET%^", targ);

    targ->set_tripped(1, "%^BOLD%^%^GREEN%^You struggle to "+
    "break free of the sticky web!%^RESET%^");
    poison_bite(targ);
    return;
}
	

