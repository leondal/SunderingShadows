#include <std.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;
int is_eating;

void create() 
{
    ::create();
    set_name("Harrison");
    set_id(({"harrison", "host", "angry host", "hhousehost"}) );
    set_short("%^BOLD%^%^BLACK%^Harrison, The Angry Host%^RESET%^");
    set_race("human");
    set_long("%^BOLD%^%^BLACK%^The man before you is barely five feet "+
    "tall. His looks very upset, in fact, he looks extremely angry. "+
    "He had upkept dark red hair and bright blue eyes that dart about "+
    "crazily. His face is in a constant scowl and it is wrinkled much "+
    "more than should be for his age. His shoulders are stooped and "+
    "he carries himself with an air of defeat, as if he would prefer to "+
    "be anywhere but here. His arms and legs are quite muscular, he "+
    "squeezes his hands together often, in obvious anger. He wears "+
    "a dingy black suit that has holes and patches covering other "+
    "holes.%^RESET%^");
    set_gender("male");
    set_level(32);
    set_alignment(9);
  	set_hd(32,1);
    set_body_type("human");
    set_overall_ac(-14);
    set_class("fighter");
    set_size(2);
    set_stats("strength", 24);
    set_property("swarm",1);
    set_property("no death",1);
    set_property("full attacks",1);
    set_property("no paralyze",1);
    set("aggressive",26);
    set_func_chance(55); 
    set_new_exp(26, "normal");
    set_hp(1450 + random(201));
    set_monster_feats(({
        "parry",
        "scramble",
        "stab",
    }));
    set_funcs(({"devour"}));
}

void continue_eating(object vic, string lim)
{
    int dam;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(vic)) return;
    if(!stringp(lim)) return;
    me = TO->query_short();
    tell_object(vic, me+"%^BOLD%^%^RED%^ continues eating into your "+lim+"!%^RESET%^");
	
    tell_room(ETO, me+"%^BOLD%^%^RED%^ continues eating into "+vic->QCN+"%^BOLD%^%^RED%^'s "+
    lim+"!%^RESET%^", vic);
    dam = roll_dice(3,12) + (6 * is_eating);
    is_eating++;
    vic->cause_typed_damage(vic, lim, dam, "piercing");
	
    if(vic->reflex_save(25)) 
    {
        tell_object(vic, "%^BOLD%^%^BLACK%^You struggle and finally manage to knock "+me+
        "%^BOLD%^%^BLACK%^ off of your "+lim+"%^BOLD%^%^BLACK!%^RESET%^");
	
        tell_room(ETO, vic->QCN+"%^BOLD%^%^BLACK%^ struggles and is finally able to knock "+me+
        "%^BOLD%^%^BLACK%^ off of "+vic->QP+" " +lim+"!%^RESET%^", vic);
        is_eating = 0;
        return;
    }
    else
    {
        tell_object(vic, me+"%^BOLD%^%^BLACK%^ continues chewing deep into your "+lim+"!%^RESET%^");
		
        tell_room(ETO, me+"%^BOLD%^%^BLACK%^ continues chewing deeper into "+vic->QCN+"%^BOLD%^%^BLACK%^"+
        "'s "+lim+"!%^RESET%^", vic);

        if(!vic->will_save(25)) 
        {
            vic->set_paralyzed(8, "%^BOLD%^%^RED%^You can focus only on the searing pain in your "+
            lim+"!%^RESET%^");
        }
        call_out("continue_eating", 5, vic, lim);
        return;
    }
}

void devour(object targ)
{
    string me, tlim;
    int dam;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(is_eating) return;
    me = TO->query_short();

    tell_room(ETO, me+" %^BOLD%^%^RED%^growls and screeches!%^RESET%^");

    switch(random(10))
    {
        case 0..5:
            tell_object(targ, me +"%^BOLD%^%^BLACK%^ runs toward you in a "+
            "blind rage, jumping at you when he gets close!%^RESET%^");
			
            tell_room(ETO, me+" %^BOLD%^%^BLACK%^ runs toward "+targ->QCN+
            "%^BOLD%^%^BLACK%^ in a blind rage, jumping at "+targ->QO +
            " when he gets close!%^RESET%^", targ);
            if(targ->reflex_save(25)) 
            {
                tell_object(targ, "%^BOLD%^%^RED%^You are able to move just in "+
                "time and "+me+" falls flat on his face!%^RESET%^");

                tell_room(ETO, targ->QCN+"%^BOLD%^%^RED%^ is able to move just in "+
                "time and "+me+"%^BOLD%^%^BLACK%^ falls flat on his face!%^RESET%^", targ);
                TO->set_tripped(1, "You are struggling to get back up!");			
            }
            else
            {
                tlim = targ->return_target_limb();
                tell_object(targ, "%^BOLD%^%^BLACK%^You are unable to move "+
                "in time and "+me+"%^BOLD%^%^BLACK%^ lands on you, he begins "+
                "biting down into your "+tlim+" and starts chewing!%^RESET%^");

                tell_room(ETO, targ->QCN+"%^BOLD%^%^BLACK%^ is unable to move "+
                "in time and "+me+" %^BOLD%^%^BLACK%^ lands on "+targ->QO+", he "+
                "begins biting down into "+targ->QP+" "+tlim+" and starts chewing!%^RESET%^", targ);
                dam = roll_dice(12, 8);
                targ->cause_typed_damage(targ, tlim, dam, "piercing");
                is_eating = 1;
                call_out("continue_eating", 5, targ, tlim);
            }
            break;
        case 6..9:
            tell_room(ETO, me + "%^BOLD%^%^BLACK%^ runs toward the "+
            "table in a blind rage, quickly devouring handfuls of the human "+
            "limbs, healing his wounds!%^RESET%^");
            TO->heal(roll_dice(10,10));
            break;
    }
    return;
}



