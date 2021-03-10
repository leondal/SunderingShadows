#include <std.h>
#include "../undead.h"

inherit CREATURE;

int FLAG=0;

create() 
{
    int level;
    object ob;
    ::create();
    set_name("dire wolf");
    set_id(({"wolf", "dire wolf"}));
    set_short("%^RED%^Dire Wolf%^RESET%^");
    set_long("The Dire wolf is a feirce beast which wonders the Peth forest in "
        "search of prey to feed on. Lord Kartakass raises them and releases "
        "them upon the island to help him hunt down peasants and stray soldiers.  "
        "They corner their prey then summon other wolves to help tear their "
        "victim limb from limb.");
    set_race("dire wolf");
    set_body_type("quadruped");
    set_gender("male");
    set_class("fighter");
    set_guild_level("fighter", 15+roll_dice(1,6));
    set_hd(20,8);
    set_exp(8000);
    set_new_exp(25,"normal");
    set_speed(30);
    nogo("one");
    set_hp(200+roll_dice(5,10));
    set_overall_ac(0 - roll_dice(1,6));
    set("aggressive", 20);
    set_alignment(9);
    set_size(2);
    set_stats("strength", 19);
    set_funcs(({"bite","call_help"}));
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

void call_help(object targ)
{
    if(FLAG == 1) { bite(targ); return; }
    call_out("wolves",5,TO);
    FLAG = 1;
    return;
}

void wolves()
{
    int i;
    if(!objectp(TO)) { return; }

    switch(random(5))
    {
    case 0..2:
        tell_room(ETO, "%^BOLD%^Howls echo back from "
            "all around the forest!%^RESET%^");
        break;
    case 3:
        tell_room(ETO, "%^RED%^Several wolves answer "
            "the howl and attack!%^RESET%^");
        for(i=0;i<(roll_dice(1,3));i++)
        {
            new(MON"wolf")->move(ETO);
        }
        break;
    case 4:
        tell_room(ETO, "%^RED%^Several wolves answer "
            "the howl and attack!%^RESET%^");
        for(i=0;i<(roll_dice(1,6));i++)
        {
            new(MON"wolf")->move(ETO);
        }
        break;
    }

}