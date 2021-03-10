#include <std.h>
#include "../keep.h"

inherit WEAPONLESS;

void create()
{
	::create();
    set_name("A troll guard");
    set_short("%^BOLD%^%^GREEN%^A troll guard%^RESET%^");
    set_id(({"guard","troll guard","troll"}));
    
    set_long("%^BOLD%^%^GREEN%^This thin creature stands nearly "+
    "nine feet tall.  Its body is strangely out of proportion as "+
    "its legs and arms are both long and hindering.  "+
    "Its legs end in grotesque three-toed feet and its arms end "+
    "with powerful, clawed hands.  Its skin is a sickly green "+
    "and a mass of iron gray hairlike substance grows on the "+
    "top of its head.%^RESET%^");

    set_hd(22,2);
    set_max_hp(425 + random(31));
    set_hp(query_max_hp());
    add_search_path("/cmds/fighter");
    set_new_exp(20, "normal");
    set_overall_ac(-5);
    set_body_type("humanoid");
    set_size(3);
    set_gender("male");
    set_race("troll");
    set_stats("strength", 18);
    set_stats("dexterity", 18);
    set_stats("constitution", 18);
    set_stats("intelligence", 14);
    set_stats("charisma", 6);
    set_stats("wisdom", 12);
    set_alignment(9);
    set_property("magic resistance", 5);
    set_property("full attacks", 1);
    set_property("swarm",1);
    add_limb("left claw","left hand",0,0,0);
    add_limb("right claw","right hand",0,0,0);
    set_attack_limbs(({"left claw", "right claw"}));	
    set_attacks_num(4);
    set("aggressive",25);
    set_func_chance(50);
    set_funcs( ({"rage"}) );
    set_damage(4,4);
    MOB_TR_D->do_treasure(TO,"B");
    set_max_level(25);
	set_parrying(1);
}

void rage(object targ) 
{
    int dam, x, hits;
    hits = 1 + random(3);
    set_property("magic",1);

    for(x = 0;x < hits;x++) 
    {
        tell_room(ETO, "%^BOLD%^%^RED%^The troll slashes " + 
        targ->query_cap_name() + "%^BOLD%^%^RED%^ in "+
        "the face with its claws!%^RESET%^", targ);
        tell_object(targ,"%^BOLD%^%^RED%^The troll slashes "+
        "you in the face with its claws!%^RESET%^");
        dam = roll_dice(3,6);
        targ->do_damage("head",dam);
        TO->add_hp((dam / 2));
    }

    set_property("magic",-1);
    return;	
}

void heart_beat() 
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(query_hp() < query_max_hp()) 
    {
        TO->add_hp(1 + random(3));
        return;
    }
    return;
}