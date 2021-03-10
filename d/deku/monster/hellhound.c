#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
inherit WEAPONLESS;

void create() 
{
    ::create();
    set_name("hell hound");
    set_id(({"hell hound","Hell hound","hellhound","hound", "saidedekufiremon"}));
    set_race("hell hound");
    set_gender("female");
    set_short("%^RED%^Vicious h%^RESET%^%^YELLOW%^e"+
    "%^RESET%^%^RED%^ll h%^RESET%^%^YELLOW%^ou%^RESET%^%^RED%^nd%^RESET%^");
    set_long("%^RED%^This rusty red dog stands nearly four feet tall at "+
    "the shoulders.  Its eyes are a deep, %^BOLD%^glowing%^RESET%^%^RED%^ "+
    "red, while its exposed fangs are a %^BOLD%^%^BLACK%^sooty black"+
    "%^RESET%^%^RED%^.  Its bulging body heaves involuntarily as it "+
    "growls insanely and stares off into the distance with a very "+
    "vacant look.  It constantly scrapes the floor and paces about, "+
    "suggesting, that despite its vacant and very inhuman expression, "+
    "it is always alert.%^RESET%^");
    set_body_type("humanoid");
    set_alignment(9);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_property("swarm",1);
    add_limb("left foreleg", "left hand", 0, 0, 0);
    add_limb("right foreleg","right hand",0,0,0);
    set_attack_limbs(({"left foreleg", "right foreleg"}));	
    set("aggressive",25);
    set_max_level(30);
    set_hd(22,1);
    set_class("fighter");
    set_size(2);
    set_stats("dexterity", 17);
    set_stats("strength", 17);
    set_funcs(({"breathe", "bite"}));
    set_func_chance(25);
    set_hp(245 + random(21));
    set_max_hp(query_hp());
    //set_exp(5000);	
    set_new_exp(25, "normal");
    set_damage(2,4);
    set_attacks_num(2);
    //add_attack_bonus(5); 
    set_speed(40 + random(41));
    set_overall_ac(-2);
    set_nogo(({FTUN_ROOMS"kinordas_chamber", FTUN_ROOMS"war_mongrels_tunnel10"}));
}

void breathe(object targ) 
{
    int dam;
    if(!objectp(targ)) return;
    if(targ->id("saidedekufiremon")) return;
    dam = roll_dice(4, 6);
    if(SAVING_D->saving_throw(targ,"breath_weapon"))
    {
        dam = dam/2;
    }
    tell_object(targ, "%^RED%^The hell hounds breath soaks you "+
    "with a scorching %^BOLD%^%^RED%^F%^YELLOW%^L%^RED%^A%^YELLOW%^M"+
    "%^RED%^E%^YELLOW%^!%^RESET%^");
	
    tell_room(environment(targ), "%^BOLD%^%^RED%^The hell hounds breath "+
    "soaks "+targ->query_cap_name()+" with a scorching flame!%^RESET%^",
    ({targ}));
    targ->do_damage("torso", dam);
    return;
}

void bite(object targ)
{
    int dam;
    string tlimb;
    if(!objectp(targ)) return;
    if(targ->id("saidedekufiremon")) return;
    dam = roll_dice(10, 4);
    if(targ->reflex_save(10))
    {
        tell_object(targ, "%^BOLD%^%^BLACK%^The hell hounds leaps at "+
        "you, its teeth gnashing, and you narrowly avoid its vicious mawl!"+
        "%^RESET%^");
        tell_room(environment(targ), "%^BOLD%^%^BLACK%^The hell hound "+
        "leaps at "+targ->query_cap_name()+" and "+
        targ->query_subjective()+" narrowly avoids its vicious mawl!"+
        "%^RESET%^", ({targ}));
        return;
    }
    tlimb = targ->return_target_limb();
    tell_object(targ, "%^BOLD%^%^RED%^The hell hounds leaps at "+
    "you, its teeth gnashing, and latches onto your "+tlimb+
    ",biting down viciously!%^RESET%^");
    tell_room(environment(targ), "%^BOLD%^%^RED%^The hell hound "+
    "leaps at "+targ->query_cap_name()+" and "+
    "latches onto "+targ->query_possessive()+ " " +tlimb +
    ",biting down viciously!%^RESET%^",({targ}));
    targ->do_damage(tlimb, dam);
    return;
}