#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;

create() {
    ::create();
    set_name("narameon");
    set_id(({"narameon","creature","disfigured creature"}));
    set_gender("male");
    set_race("disfigured creature");
    set_short("A disfigured male creature");
    
    set_long("%^YELLOW%^The facial features of this creature have "+
    "been twisted and disfigured beyond recognition.  The only "+
    "recognizable features to his face are the eyes of deep "+
    "%^BLUE%^azure%^YELLOW%^ that burn with an intense "+
    "anger or hatred.  A pile of %^BOLD%^%^BLACK%^dark%^RESET%^ "+
    "%^YELLOW%^and oily hair hangs down from his head and "+
    "conceals whatever type of ears he may have.  His neck bulges "+
    "with vains that shine a sickly %^BOLD%^%^GREEN%^green"+
    "%^RESET%^%^YELLOW%^ from beneath his slightly grayed flesh.  "+
    "An emblem, that of %^RED%^two opened palms%^RESET%^%^YELLOW%^ "+
    "each holding a %^BOLD%^%^WHITE%^skeletal wand%^RESET%^%^YELLOW%^ "+
    "has been brutally carved into his naked chest.  His arms are "+
    "twisted and bulged with muscles that appear to have somehow "+
    "taken on a life of their own, each of them constantly "+
    "moving and twitching just beneath the surface.  His lower "+
    "body is covered completely by a strange %^MAGENTA%^"+
    "brown%^YELLOW%^ and rough cloth, leaving no clue as to its "+
    "state, but you reason it is not well.%^RESET%^");
        
    set_body_type("human");
    set_alignment(9);
    set_hd(32 + random(3));
    set_class("mage");
    set_mlevel("mage",34);
    set_guild_level("mage",20);
    set_stats("strength",19);
    set_stats("constitution",15);
    set_stats("wisdom",15);
    set_stats("intelligence",22);
    set_stats("dexterity",19);
    set_stats("charisma",10);
    set("aggressive",30);
    set_overall_ac(-18);
    set_hp(2800 + random(250));
    new(HHOB+"ethereal_scimitar")->move(TO);
    command("wield scimitar");
    new(HHOB+"ethereal_scimitar")->move(TO);
    command("wield scimitar");
    set_new_exp(33, "boss");
    set_funcs(({"quick_attack","vicious_swing","downward_thrust",
    "fire_and_lightning"}));
    set_func_chance(75); 
    set_property("full attacks",1);
}


void lightning_fit() 
{
    int bolts;
    object targ;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    bolts = 2 + random(4);
    while(bolts--) 
    {
        while(!objectp(targ)) 
        {
            targ = all_living(ETO)[random(sizeof(all_living(ETO)))];
            if(targ->query_true_invis()) 
            {
                targ = 0;
            }
        }
        if(!objectp(targ)) continue;
        tell_room(ETO,"%^BOLD%^%^YELLOW%^A bolt of lightning "+
        "strikes "+targ->QCN+"%^BOLD%^%^YELLOW%^!%^RESET%^",targ);

        tell_object(targ,"%^BOLD%^%^YELLOW%^You are struck "+
        "by a bolt of stray lightning!%^RESET%^");
        if(targ == TO) 
        {
            tell_room(ETO,"%^RED%^The creature absorbs the "+
            "stray %^YELLOW%^lightning%^RESET%^%^RED%^ and "+
            "seems to grow stronger!%^RESET%^");
            TO->add_hp(75 + random(75));
            targ = 0;
            continue;
        }
        targ->add_attacker(TO);
        targ->continue_attack();
        
        if(!targ->reflex_save(32))
        {
            targ->cause_typed_damage(targ, "torso",roll_dice(20, 8), "electricity");
            continue;
        }
        targ->cause_typed_damage(targ, "torso",roll_dice(10,8), "electricity");
        targ = 0;
        continue;
    }
}

void fire_and_lightning(object targ) 
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    tell_room(ETO,"%^RED%^The creature cackles insanely and "+
    "conjures a ball of %^BLUE%^blue flame%^RED%^ in its "+
    "right hand, before suddenly hurling it at "+
    targ->QCN+"%^RED%^!%^RESET%^",targ);
    
    tell_object(targ,"%^RED%^The creature cackles insanely and "+
    "conjures a ball of %^BLUE%^blue flame%^RED%^ in its "+
    "right hand and then suddenly hurls it at you!%^RESET%^");

    if(!targ->reflex_save(32)) 
    {
        
        tell_object(targ,"%^BOLD%^%^BLACK%^The ball of %^RESET%^"+
        "%^BLUE%^blue flame%^BOLD%^%^BLACK%^ impacts your "+
        "chest with tremendous momentum and bursts into a series "+
        "of %^BOLD%^%^WHITE%^lightning bolts!%^RESET%^");
        
        tell_room(ETO,"%^BOLD%^%^BLACK%^The ball of %^RESET%^"+
        "%^BLUE%^blue flame%^BOLD%^%^BLACK%^ impacts with "+
        targ->QCN+"%^BOLD%^%^BLACK%^'s chest and burst into a "+
        "series of %^BOLD%^%^WHITE%^lightning bolts!%^RESET%^",targ);
        
        call_out("lightning_fit",1 + random(3));
        targ->cause_typed_damage(targ, "torso",roll_dice(24, 10), "fire");
        return 1;
    }
    tell_object(targ,"%^BOLD%^%^BLACK%^The ball of %^RESET%^"+
    "%^BLUE%^blue flame%^BOLD%^%^BLACK%^ flies past you and "+
    "bursts into a series of %^BOLD%^%^WHITE%^lightning bolts!"+
    "%^RESET%^");
    
    tell_room(ETO,"%^BOLD%^%^BLACK%^The ball of %^RESET%^"+
    "%^BLUE%^blue flame%^BOLD%^%^BLACK%^ flies past "+
    targ->QCN+"%^BOLD%^%^BLUE%^ and bursts into a "+
    "series of %^BOLD%^%^WHITE%^lightning bolts!%^RESET%^",targ);
    call_out("lightning_fit",1);

    return 1;


}

void downward_thrust(object targ) 
{
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;

    tell_object(targ,"%^BLUE%^The creature swings its scimitar "+
    "down at you, leaving a trail of %^BOLD%^%^BLUE%^blue "+
    "flame%^RESET%^%^BLUE%^ in its steed!%^RESET%^");

    tell_room(ETO,"%^BLUE%^The creature swings it scimitar "+
    "downward at "+targ->QCN+"%^BLUE%^ and a trail of "+
    "%^BOLD%^%^BLUE%^blue flame%^RESET%^%^BLUE%^ follows the "+
    "weapon!%^RESET%^",targ);
    
    if(!targ->reflex_save(32)) 
    {
        tell_room(ETO,"%^BOLD%^%^BLUE%^The scimitar connects with "+
        targ->QCN+"%^BOLD%^%^BLUE%^ and cuts deep into "+
        targ->QP+" flesh!%^RESET%^",targ);
        
        tell_object(targ,"%^BOLD%^%^BLUE%^The scimitar connects with "+
        "you and slices deep into your flesh!%^RESET%^");

        targ->cause_typed_damage(targ, "torso",roll_dice(20, 10), "slashing");
        return 1;
    }
    tell_room(ETO,"%^BOLD%^%^BLUE%^The scimitar falls wide and "+
    "misses "+targ->QCN+"%^BOLD%^%^BLUE%^ by a good foot!%^RESET%^",
    targ);
    tell_object(targ,"%^BOLD%^%^BLUE%^The scimitar falls wide "+
    "and misses you by a good foot!%^RESET%^");
    return 1;
}

void vicious_swing(object targ) 
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;

    tell_object(targ,"%^BOLD%^%^BLACK%^The creature swings its "+
    "scimitar at you with all of its might!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^BLACK%^The creature swings with all "+
    "its might at "+targ->QCN+"!%^RESET%^",targ);
    
    limb = targ->return_target_limb();
    if(!targ->reflex_save(32)) 
    {
       
        tell_object(targ,"%^BOLD%^%^WHITE%^The fierce blow connects with your "+
        limb+" and its force manages to knock you off balance!"+
        "%^RESET%^");
        targ->set_tripped(2,"%^RED%^You struggle to regain your "+
        "balance!%^RESET%^");
        targ->cause_typed_damage(targ, limb,roll_dice(16,12), "slashing");

        tell_room(ETO,"%^BOLD%^%^WHITE%^The fierce blow "+
        "connects with "+targ->QCN+"%^BOLD%^%^WHITE%^'s "+
        limb+" and the force of it knocks "+targ->QO+
        " off balance!%^RESET%^",targ);
        return;
    }
    tell_object(targ,"%^BOLD%^%^WHITE%^The fierce blow grazes "+
    "your "+limb+"!%^RESET%^");
    targ->cause_typed_damage(targ, limb,roll_dice(6,10), "slashing");
    tell_room(ETO,"%^BOLD%^%^WHITE%^The fierce blow grazes "+
    targ->QCN+"%^BOLD%^%^WHITE%^'s "+limb+"!%^RESET%^",targ);
    return;
}
   
void quick_attack(object targ) 
{
    int hits, x;
    string limb;

    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;
	
    
    tell_room(ETO,"%^RED%^The creature growls and laughs wildy "+
    "as he dives headlong and then rolls to the side, thrusting his "+
    "scimitar repeatedly at "+targ->QCN+"%^RED%^!%^RESET%^",({targ,TO}));
    
    tell_object(targ,"%^RED%^The creature growls and laughs widly "+
    "as he dives headlong and then rolls to the side, thrusting "+
    "his scimitar at you repeatedly!%^RESET%^");
    
    hits = 2 + random(3);
    for(x = 0;x < hits;x++) 
    {
        limb = targ->return_target_limb();
        if(!targ->reflex_save(32)) 
        {
            tell_object(targ,"%^BLUE%^A wild thrust "+
            "strikes you in the "+limb+"!%^RESET%^");
	
            tell_room(ETO,"%^BLUE%^A wild thrust "+
            "strikes "+targ->QCN+"%^BLUE%^ in the "+
            limb+"!%^RESET%^",targ);
            targ->cause_typed_damage(targ, limb,roll_dice(10,8), "slashing");    
            continue;
		}
        tell_object(targ, "%^BLUE%^You manage to move just in time!"+
        "%^RESET%^");
        tell_room(ETO, targ->QCN+"%^BLUE%^ manages to move just in time!%^RESET%^", targ);
        continue;
    }
}

    





