#include <std.h>
#include <daemons.h>
#include "traps.h"
inherit TRAP_INH;

void create()
{
    ::create();
    set_damage_type("paralyze");
    set_my_trap_name("concussion");
    set_my_die(2);	
    set("stun_message", "%^BOLD%^%^BLACK%^You are stunned by the "+
    "concussion from the blast!%^RESET%^");

    set("lore_string", "%^BOLD%^%^BLACK%^This trap was designed with "+
    "the intention of stunning a single target with a focused blast of "+
    "concussive energy.%^RESET%^");

    //set("no_fence", 1); - thinking this way so they wont show in 
        //for sale in a fence - if we want some traps that dont
}

void trap_activated(object who)
{
    object env;
    int x, dam;
    if(!objectp(TO)) return;
    if(!objectp(who)) return;
    if(!objectp(environment(who))) return;
    env = environment(who);
	
    tell_object(who, "%^BOLD%^%^CYAN%^A focused blast of concussive "+
    "energy pulses from "+TO->query_origin_object()+ 
    " toward you!%^RESET%^");

    tell_room(env, "%^BOLD%^%^CYAN%^A focused blast of concussive "+
    "energy pulses from "+TO->query_origin_object()+
    " toward "+who->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^", who);

    if(do_trap_save(who)) 
    {
        tell_object(who, "%^BOLD%^%^CYAN%^The blast of energy "+
        "%^BOLD%^%^RED%^COLLIDES%^BOLD%^%^CYAN%^ with you, leaving "+
        "you momentarily stunned, but otherwise unharmed!%^RESET%^");
		
        tell_room(env, "%^BOLD%^%^CYAN%^The blast of energy "+
        "%^BOLD%^%^RED%^COLLIDES%^BOLD%^%^CYAN%^ with "+
        who->QCN+"%^BOLD%^%^CYAN%^, leaving "+who->QO+
        " momentarily stunned!%^RESET%^", who);
		
        do_trap_damage(who, 1, "stun");
        return;
    }
    else
    {
        tell_object(who, "%^BOLD%^%^CYAN%^The blast of energy "+
        "%^BOLD%^%^BLACK%^ENGULFS%^BOLD%^%^CYAN%^ you, leaving you "+
        "stunned and slightly disoriented!%^RESET%^");

        tell_room(env, "%^BOLD%^%^CYAN%^The blast of energy "+
        "%^BOLD%^%^BLACK%^ENGULFS%^BOLD%^%^CYAN%^ "+    
        who->QCN+"%^BOLD%^%^CYAN%^, leaving "+who->QO+
        " stunned!%^RESET%^", who);	

        do_trap_damage(who, 0, "stun");
        return;	
    }
    return;
}


