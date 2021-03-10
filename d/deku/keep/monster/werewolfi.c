#include <std.h>
#include "../keep.h"

inherit WEAPONLESS;

void create()
{
    ::create();
    set_body_type("humanoid");
    set_gender("male");
    set_race("werewolf");
    set_alignment(9);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_property("swarm",1);
    add_limb("left claw","left hand",0,0,0);
    add_limb("right claw","right hand",0,0,0);
    set_attack_limbs(({"left claw", "right claw"}));	
    set("aggressive",25);
    set_func_chance(20);
    set_max_level(25);
    //add_attack_bonus(3);   
    set_parrying(1);   
}

void bite(object targ)
{

    tell_room(ETO, "%^BOLD%^%^WHITE%^The werewolf jumps onto " + 
    targ->query_cap_name() + "%^BOLD%^%^WHITE%^ and shoves its "+
    "claws into " + targ->query_possessive() + "%^BOLD%^%^WHITE%^ "+
    "back and begins biting " + targ->query_objective() + 
    "%^BOLD%^%^WHITE%^ in the face!%^RESET%^", targ);

    tell_object(targ,"%^BOLD%^%^WHITE%^The werewolf jumps onto "+
    "you and shoves its claws into your back and begins biting "+
    "you in the face!%^RESET%^");
    targ->do_damage("head",roll_dice(6,6));
    if(!random(5)) 
    {
        targ->set_paralyzed(6,"%^RED%^You struggle to free yourself "+
        "from the werewolf!%^RESET%^");
    }
    return;
	
}

void maim(object targ)
{
    int hits,x;
    hits = random(3) + 1;

    for(x = 0;x < hits;x++) 
    {
        tell_room(ETO,"%^BOLD%^%^RED%^The werewolf growls "+
        "loudly and hits " + targ->query_cap_name() + 
        "%^BOLD%^%^RED%^ in the head with its massive hand!%^RESET%^",targ);
        tell_object(targ,"%^BOLD%^%^RED%^The werewolf growls "+
        "loudly and hits you in the head with its massive hand!%^RESET%^");
        targ->do_damage("head",roll_dice(4,8));
    }
    return;
}

