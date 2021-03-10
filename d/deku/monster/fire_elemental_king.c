#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

void create() 
{
    ::create();
    set_name("Fire Elemental King");
    set_id(({"elemental","fire elemental", "fire elemental king", "king"}));
    set_race("fire elemental");
    set_gender("neuter");
    set_short("%^RED%^D%^YELLOW%^a%^RED%^"+
    "%^YELLOW%^l%^RED%^r%^YELLOW%^a%^RED%^g%^YELLOW%^"+
    "w%^RED%^i%^YELLOW%^a%^RED%^n, Fire E%^YELLOW%^l%^RESET%^%^RED%^"+
    "e%^YELLOW%^m%^RESET%^%^RED%^e%^YELLOW%^n%^RESET%^%^RED%^t"+
    "%^YELLOW%^a%^RESET%^%^RED%^l%^RESET%^%^RED%^ King");

    set_long("%^RED%^Before you stands one of the most disturbing beasts "+
    "you have ever laid eyes on.  It stands nearly twenty feet tall and "+
    "is composed entirely of a roaring, rolling flame that threatens to "+
    "engulf this entire area.  Its massive body moves about the "+
    "area with total disregard for what might be destroyed by its "+
    "presence.  Despite this, deep within its eyes, is what appears to "+
    "be a glimmer of intelligence, and unlike the other elementals "+
    "that wander this place, there is no hatred, rather "+
    "a look of understanding and tranquility.  This beast "+
    "wears no garment to broadcast its position, but you "+
    "know, without any doubt, that this creature "+
    "is considered king amongst the other elementals of "+
    "this place.%^RESET%^");

    set_body_type("humanoid");
    set_alignment(7);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_max_level(30);
    set_hd(26,1);
    set_class("fighter");
    set_size(3);
    set_stats("dexterity", 18);
    set_stats("strength", 20);
    set_funcs(({"inferno"}));
    set_func_chance(20);
    set_hp(650 + random(51));
    set_max_hp(query_hp());
	//set_exp(12000);
    set_new_exp(25, "very high");
    set_attack_limbs(({"left hand", "right hand"}));
    set_damage(3,6);
    set_attacks_num(4);
    add_attack_bonus(5); 
    set_overall_ac(-8);
}

void heart_beat()
{
    object k, *atts;
    int y;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    atts = TO->query_attackers();
    if(!sizeof(atts)) return;
    for(y = 0;y < sizeof(atts);y++) 
    {
        if(atts[y]->id("saidedekufiremon")) 
        {
            TO->remove_attacker(atts[y]);
            atts[y]->remove_attacker(TO);
            return;
        }
    }
}

void inferno(object targ) 
{
    int dam, x;
    object *targs;
    if(!objectp(TO)) return;
    if(objectp(TO)) 
    {
        targs = all_living(ETO);
        targs -= ({TO});
    }
    dam = roll_dice(14, 6);
    tell_room(ETO, "%^RED%^With a sudden ferocious sound, that "+
    "could only be described as an inhuman growl of rage, "+
    "the fire elemental king erupts into a flaming inferno, engulfing "+
    "everything in the immediate area!%^RESET%^", ({TO}));
	
    for(x = 0;x < sizeof(targs);x++)
    {
        if(!objectp(targs[x])) continue;
        if(targs[x] == TO) continue;
        if(targs[x]->id("saidedekufiremon")) continue;
        if(targs[x]->reflex_save(14))
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

