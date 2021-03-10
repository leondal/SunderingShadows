#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
inherit WEAPONLESS;

void create() 
{
    ::create();
    set_name("fire elemental");
    set_id(({"elemental","fire elemental", "saidedekufiremon"}));
    set_race("fire elemental");
    set_gender("neuter");
    set_short("%^RED%^Towering fire e%^YELLOW%^l%^RESET%^%^RED%^"+
    "e%^YELLOW%^m%^RESET%^%^RED%^e%^YELLOW%^n%^RESET%^%^RED%^t"+
    "%^YELLOW%^a%^RESET%^%^RED%^l%^RESET%^");

    set_long("%^RED%^This towering abomination stands close to eight "+
    "feet tall and roars to life from an inextinguishable flame.  Its "+
    "body appears almost human, but all of its features, save for "+
    "its appendages and its glowing eyes are hidden behind the "+
    "flame that engulfs its existence.  Swinging dangerously and "+
    "with suprising dexterity, from its torso, "+
    "are the masses of flame that are its arms and legs, each "+
    "a darker and more violent flame than the rest of its body.  "+
    "This creature stands guard over this place, like a "+
    "flaming statue that is every alert and according to its eyes, "+
    "which flicker not only with fire but with an unmistakable "+
    "hatred for living beings, ready to destroy all who it "+
    "encounters.%^RESET%^");

    set_body_type("humanoid");
    set_alignment(9);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_property("swarm",1);
    set("aggressive",25);
    set_max_level(30);
    add_attack_bonus(5);  
    set_hd(22, 1);
    set_class("fighter");
    set_size(3);
    set_stats("dexterity", 22);
    set_stats("strength", 18);
    set_funcs(({"inferno"}));
    set_func_chance(15);
    set_hp(285 + random(31));
    set_max_hp(query_hp());
    //set_exp(5000);
    set_new_exp(25, "normal");
    set_attack_limbs(({"left hand", "right hand"}));
    set_damage(2,6);
    set_attacks_num(2);
    //add_attack_bonus(5); 
    set_speed(40 + random(41));
    set_overall_ac(-3);
    set_nogo(({FTUN_ROOMS"kinordas_chamber", FTUN_ROOMS"war_mongrels_tunnel10"}));
}

void inferno(object targ) 
{
    int dam, x;
    object *targs;
    if(!objectp(TO)) return;
    if(objectp(TO)) 
    {
        targs = all_living(ETO);
    }
    dam = roll_dice(10, 6);
    tell_room(ETO, "%^RED%^With a sudden ferocious sound, that "+
    "could only be described as an inhuman growl of rage, "+
    "the fire elemental erupts into a flaming inferno, engulfing "+
    "everything in the immediate area!%^RESET%^", ({TO}));
	
    for(x = 0;x < sizeof(targs);x++)
    {
        if(!objectp(targs[x])) continue;
        if(targs[x]->reflex_save(10))
        {
            dam = dam/2;
        }
        tell_object(targs[x], "%^RED%^You are engulfed by the %^BOLD%^"+
        "%^RED%^I%^YELLOW%^N%^BOLD%^%^RED%^F%^YELLOW%^E%^RED%^R"+
        "%^YELLOW%^N%^RED%^O%^YELLOW%^!%^RESET%^");
	
        tell_room(environment(targs[x]),targs[x]->query_cap_name()+ 
        " is engulfed by the %^BOLD%^"+
        "%^RED%^I%^YELLOW%^N%^BOLD%^%^RED%^F%^YELLOW%^E%^RED%^R"+
        "%^YELLOW%^N%^RED%^O%^YELLOW%^!%^RESET%^", ({targs[x]}));
        targs[x]->cause_typed_damage(targs[x], "torso", dam, "fire");
        continue;
    }
    return;
}

