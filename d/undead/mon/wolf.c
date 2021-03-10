#include <std.h>
#include "../undead.h"

inherit CREATURE;

create() 
{
    int level;
	::create();
    set_name("dire wolf");
    set_id(({"wolf", "dire wolf"}));
    set_short("%^RED%^Dire Wolf%^RESET%^");
	set_long("The Dire wolf is a fierce beast which wonders the Peth forest in "
        "search of prey to feed on. Lord Kartakass raises them and releases "
        "them upon the island to help him hunt down peasants and stray soldiers.  "
        "They corner their prey then summon other wolves to help tear their "
        "victim limb from limb.");

    set_race("dire wolf");
    set_body_type("quadruped");
    set_class("fighter");
    set_mlevel("fighter",15);
    set_hd(15,8);
    set_hp(200);
	set_level(15);
    set_exp(3000);
    set_new_exp(25,"normal");
    set_alignment(9);
    set_size(2);
    set_stats("strength", 18);
    set_funcs(({"bite"}));
    set_func_chance(15);
}
	
void bite(object targ) 
{    
    if(ROLLSAVE(targ,PPD)) 
    {
      
        tell_object(targ,"%^BOLD%^%^RED%^The Dire Wolf lunges at you, jaws wide open!\n"
            "%^BOLD%^%^RED%^His bite lands and tears into your flesh!");
        tell_room(ETO,"%^BOLD%^%^RED%^The Dire Wolf lunges at "+targ->QCN+" "
            "sinking its teeth into "+targ->QS+"!",targ);
        targ->do_damage(targ->return_limb(),roll_dice(2,6));
        return;
    } 

    tell_object(targ,"%^RED%^The Dire Wolf tears at your limbs keeping you pinned "
        "to the ground!");
    tell_room(ETO,"%^BOLD%^%^RED%^The Dire Wolf lunges at "+targ->QCN+" "
        ",pinning "+targ->QO+" to the ground!",targ);    
    targ->set_paralyzed(roll_dice(3,6),"%^GREEN%^You struggle to free yourself "
        "from the Dire Wolf's deadly grasp!");
    targ->do_damage("torso",roll_dice(4,6));
    return;
}