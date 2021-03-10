#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit OBJECT;

int myDC;

object myCaster;

void set_dc(int x) { myDC = x; }

int is_spell() { return 1; }

object query_caster(){ return myCaster; }

void dest_effect()
{
    if(objectp(TO)) TO->remove();
}

void set_caster(object who)
{
    if(objectp(who)) myCaster = who;
}

void do_start()
{
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
    tell_object(ETO, "%^BOLD%^%^RED%^Your body begins violently vibrating!!!%^RESET%^");
    ETO->set_property("spelled", ({TO}));
    if(objectp(EETO)) 
    {
        tell_room(EETO, ETO->QCN+"%^BOLD%^%^RED%^'s body suddenly begins violently vibrating!!!%^RESET%^", ETO);
    }
    return;
}

void do_finish()
{
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
    ETO->remove_property_value("spelled", ({TO}));
    if(!myDC) myDC = 17;
    if(SAVING_THROW_D->fort_save(ETO, myDC) || ETO->query_property("no death"))
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^An excrutiating %^BOLD%^%^RED%^PAIN"+
        "%^BOLD%^%^BLACK%^ radiates throughout your entire body and "+
        "you %^GREEN%^S%^BOLD%^%^BLACK%^H%^GREEN%^"+
        "R%^BOLD%^%^BLACK%^I%^GREEN%^E%^BOLD%^%^BLACK%^K as "+
        "the vibrations finally stop!%^RESET%^");
        if(objectp(EETO))
        {
            tell_room(EETO, ETOQCN+" %^BOLD%^%^GREEN%^S%^BOLD%^%^BLACK%^H%^BOLD%^%^GREEN%^"+
            "R%^BOLD%^%^BLACK%^I%^BOLD%^%^GREEN%^E%^BOLD%^%^BLACK%^K%^BOLD%^%^GREEN%^S%^BOLD%^%^BLACK%^ in "+
            "%^BOLD%^%^RED%^PAIN%^BOLD%^%^BLACK%^ suddenly as the vibrations in "+
            ETO->QP+" body finally stop!%^RESET%^", ETO);
        }
        //should be necrotic damage - going with divine for now - Saide
        ETO->cause_typed_damage(ETO, "chest", roll_dice(myDC, 6), "divine");
        ETO->add_attacker(TO);
        ETO->continue_attack(TO);
        if(objectp(TO))
        {
            if(objectp(ETO)) 
            {
                ETO->remove_attacker(TO);
            }            
            TO->remove();
        }
        return;       
    }
    else
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^An excrutiating %^BOLD%^%^RED%^PAIN"+
        "%^BOLD%^%^BLACK%^ radiates throughout your entire body and "+
        "you %^BOLD%^%^GREEN%^S%^BOLD%^%^BLACK%^H%^BOLD%^%^GREEN%^"+
        "R%^BOLD%^%^BLACK%^I%^BOLD%^%^GREEN%^E%^BOLD%^%^BLACK%^K%^BOLD%^%^BLACK%^ as "+
        "you collapse in a heap!%^RESET%^");
        
        if(objectp(EETO))
        {
            tell_room(EETO, ETOQCN+" %^BOLD%^%^GREEN%^S%^BOLD%^%^BLACK%^H%^BOLD%^%^GREEN%^"+
            "R%^BOLD%^%^BLACK%^I%^BOLD%^%^GREEN%^E%^BOLD%^%^BLACK%^K%^BOLD%^%^GREEN%^S in "+
            "%^BOLD%^%^RED%^PAIN%^BOLD%^%^BLACK%^ suddenly before collapsing in "+
            "a heap!%^RESET%^", ETO);
        }
        ETO->set_hp(0);
        ETO->add_attacker(TO);
        ETO->continue_attack(TO);
        if(objectp(TO))
        {
            if(objectp(ETO)) 
            {
                ETO->remove_attacker(TO);
            }            
            TO->remove();
        }
        return;  
    }
    if(objectp(TO)) TO->remove();
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
    if(objectp(ETO)) 
    {
        if(living(ETO))
        {
            if(userp(ETO)) set_property("knocks unconscious", 1);
            do_start();  
            call_out("do_finish", ROUND_LENGTH * (2 + roll_dice(1, 3)));            
            return;
        }
        TO->remove();
        return;
    }
    return;
}
