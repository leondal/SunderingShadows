#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit OBJECT;

int dam, isSet;
string limb;


void dest_effect()
{
    if(objectp(TO)) TO->remove();
}

void set_for(string str, int x)
{
    if(!stringp(str)) return;
    if(!intp(x)) return;
    dam = x;
    limb = str;
}

void do_bleed()
{
    string race;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) 
    {
        TO->remove();
        return;
    }
    if(!living(ETO)) 
    {
        TO->remove();
        return;
    }
    if(ETO->query_ghost())
    {
        TO->remove();
        return;
    }
    race = (string)ETO->query_race();
    if(race == "skeleton" || race == "ooze" || race == "elemental" ||
    race == "construct")
    {
        TO->remove();
        return;
    }    
    if(!stringp(limb) || !intp(dam))
    {
        TO->remove();
        return;
    }   
    tell_object(ETO, "%^BOLD%^%^RED%^You spurt blood from your "+limb+"!%^RESET%^");      
    if(objectp(EETO)) 
    {
        tell_room(EETO, ETO->QCN+"%^BOLD%^%^RED%^ spurts blood from "+ETO->QP+" "+limb+"!%^RESET%^", ETO);
    }
    ETO->cause_typed_damage(ETO, limb, roll_dice(1, dam), "slashing");    
    if(roll_dice(1,30) > (int)ETO->query_stats("constitution")) call_out("do_bleed", ROUND_LENGTH);
    else
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The wound on your "+limb+" closes!%^RESET%^");
        TO->remove();
        return;
    }
    return;
}

void create()
{
    ::create();
    set_property("no animate", 1);
    set_property("no drop", 1);
    set_property("soulbound", 1);
}

void init()
{
    ::init();
    if(isSet) return;
    if(objectp(ETO)) 
    {
        if(living(ETO))
        {            
            if(userp(ETO)) set_property("knocks unconscious", 1);
            ETO->set_property("spelled", ({TO}));
            isSet = 1;
            call_out("do_bleed", ROUND_LENGTH);            
            return;
        }
        TO->remove();
        return;
    }
    return;
}
