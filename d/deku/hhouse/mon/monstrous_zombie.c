#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

void create() 
{
    ::create();
    set_name("monstrous zombie");
    set_id(({"zombie", "monstrous zombie", "rotting zombie"}));
    set_race("zombie");
    set_property("undead", 1);	
    if(random(2)) set_gender("male");
    else set_gender("female");
	
    switch(random(3)) 
    {
        case 0:
            set_short("%^BOLD%^%^MAGENTA%^R%^BOLD%^%^BLACK%^o%^BOLD%^%^MAGENTA%^"+
            "tt%^BOLD%^%^BLACK%^i%^BOLD%^%^MAGENTA%^ng Z%^BOLD%^%^BLACK%^o"+
            "%^BOLD%^%^MAGENTA%^mb%^BOLD%^%^BLACK%^ie%^RESET%^");
            break;
        case 1:
            set_short("%^RESET%^%^ORANGE%^Bl%^BOLD%^%^RED%^oa%^RESET%^%^ORANGE%^"+
            "t%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^d Z%^BOLD%^%^RED%^o%^RESET%^"+
            "%^ORANGE%^mb%^BOLD%^%^RED%^ie%^RESET%^");
            break;
        case 2:
            set_short("%^BOLD%^%^GREEN%^P%^BOLD%^%^WHITE%^u%^BOLD%^%^GREEN%^tr"+
            "%^BOLD%^%^WHITE%^i%^BOLD%^%^GREEN%^d Z%^BOLD%^%^WHITE%^o"+
            "%^BOLD%^%^GREEN%^mb%^BOLD%^%^WHITE%^ie%^RESET%^");
            set_property("is_putrid", 1);
            break;
    }
	
    set_long("%^BOLD%^%^GREEN%^The monstrous thing before you is horrifying to "+
    "behold. "+capitalize(TO->QS)+" was once a humanoid of some sort but that was long ago. "+
    capitalize(TO->QS)+" is now a rotting mass of animated flesh. "+
    capitalize(TO->QP)+" appendages are broken, "+
    "ripped, and oozing an acidic puss. Many of "+TO->QP+" innards are visible "+
    "through thin or open flesh and a strong odor of death and decay "+
    "hangs over it. "+capitalize(TO->QP)+" face is set in an eternal "+
    "angry scowl, "+TO->QP+" eyes are a deep %^BOLD%^%^RED%^blazing red"+
    "%^BOLD%^%^GREEN%^ that are a window into a tarnished and furious soul. "+
    capitalize(TO->QP) + " hands are now twisted and curved, ending in "+
    "vicious dripping claws.%^RESET%^"); 

    set_body_type("humanoid");
    set_alignment(9);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_property("swarm",1);
    add_limb("left claw", "left hand", 0, 0, 0);
    add_limb("right claw","right hand",0,0,0);
    set_attack_limbs(({"left claw", "right claw"}));	
    set("aggressive",29);
    set_hd(32,1);
    set_class("fighter");
    set_size(1 + random(3));
    
    set_stats("strength",19);
    set_stats("intelligence",9);
    set_stats("wisdom",9);
    set_stats("dexterity",12);
    set_stats("charisma",8);
    set_stats("constitution",10);
    
    set_funcs(({"breathe", "shred"}));
    set_func_chance(45);
    set_hp(470 + random(251));
    set_max_hp(query_hp());
    set_new_exp(32, "normal");
    set_damage(4,6);
    set_base_damage_type("slashing");
    set_base_damage_type("slashing");
    set_attacks_num(4);
    set_property("natural poisoner", 1);
    set_property("natural poison", "bloodroot");
    set_property("poison chance", 30);
    set_overall_ac(-16);
    set_property("death effects", "undead");
    set_moving(1);
    set_speed(45);
    set_nogo(({RROOMS+"23", SFROOMS+"h3"}));
}

void breathe(object targ) 
{
    int dam;
    object gas;
    string me;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    if(TO->query_property("is_putrid")) 
    {
        gas = new(HHOB+"gas_cloud");
        tell_room(ETO, me + "%^BOLD%^%^GREEN%^ opens "+TO->QP+" mouth and "+
        "expels a cloud of "+gas->query_short()+"!%^RESET%^");
        gas->move(ETO);
        return;
    }
    else
    {
        tell_object(targ, me + "%^BOLD%^%^GREEN%^ opens "+TO->QP+" mouth, "+
        "showering you in an %^BOLD%^%^RED%^a%^BOLD%^%^GREEN%^c%^BOLD%^%^RED%^"+
        "i%^BOLD%^%^GREEN%^d%^BOLD%^%^RED%^i%^BOLD%^%^GREEN%^c spray!%^RESET%^");
		
        tell_room(ETO, me + "%^BOLD%^%^GREEN%^ opens "+TO->QP+" mouth, "+
        "showering "+targ->QCN+" in an %^BOLD%^%^RED%^a%^BOLD%^%^GREEN%^c%^BOLD%^%^RED%^"+
        "i%^BOLD%^%^GREEN%^d%^BOLD%^%^RED%^i%^BOLD%^%^GREEN%^c spray!%^RESET%^", targ);
        dam = roll_dice(10, 12);
        if(targ->fort_save(30))
        {
            dam = dam/2;
        }
        targ->cause_typed_damage(targ, "torso", dam, "fire");
        return;
    }
}

void shred(object targ)
{
    int dam, hits;
    string tlimb, me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    hits = 1 + random(3) + random(3);
    tell_object(targ, me + "%^BOLD%^%^RED%^ lumbers toward you, growling "+
    "in %^BOLD%^%^BLACK%^R%^BOLD%^%^WHITE%^A%^BOLD%^%^BLACK%^G%^BOLD%^%^WHITE%^E%^BOLD%^%^RED%^"+
    "!%^RESET%^");

    tell_room(ETO, me + "%^BOLD%^%^RED%^ lumbers toward "+targ->QCN+"%^BOLD%^%^RED%^, growling "+
    "in %^BOLD%^%^BLACK%^R%^BOLD%^%^WHITE%^A%^BOLD%^%^BLACK%^G%^BOLD%^%^WHITE%^E%^BOLD%^%^RED%^"+
    "!%^RESET%^", targ);

    while(hits--)
    {

        if(targ->reflex_save(35))
		{
            tell_object(targ, me+"%^BOLD%^%^MAGENTA%^ swipes at you with "+TO->QP+
            " vicious claws but you manage to move just in time!%^RESET%^");

            tell_room(ETO, me+"%^BOLD%^%^MAGENTA%^ swipes at "+targ->QCN+"%^BOLD%^%^MAGENTA%^"+
            " with "+TO->QP+" vicious claws but "+targ->QS+
            " manage to move just in time!%^RESET%^", targ);
            continue;
        }

        tlimb = targ->return_target_limb();

        tell_object(targ, me +"%^BOLD%^%^RED%^ slashes deep into your "+tlimb+
        " with "+TO->QP+" vicious claws!%^RESET%^");

        tell_room(ETO, me +"%^BOLD%^%^RED%^ slashes deep into "+targ->QCN+
        "%^BOLD%^%^RED%^'s "+tlimb+" with "+TO->QP+" vicious claws!%^RESET%^", targ);
        dam = roll_dice(10, 8);
        targ->cause_typed_damage(targ, tlimb, dam, "slashing");
        continue;
    }
    return;
}