#include <std.h>
#include <daemons.h>
#include "traps.h"
inherit TRAP_INH;

void create()
{
    ::create();
    set_damage_type("piercing");
    set_my_trap_name("spike");
    set_my_die(8);	
    //set("no_fence", 1); - thinking this way so they wont show in 
        //for sale in a fence - if we want some traps that dont

    set("lore_string", "%^BOLD%^%^WHITE%^This trap was designed with "+
    "the intention of jabbing numerous tiny spikes into a single "+
    "target.%^RESET%^");
}

void trap_activated(object who)
{
    object env;
    int x, dam;
    if(!objectp(TO)) return;
    if(!objectp(who)) return;
    if(!objectp(environment(who))) return;
    env = environment(who);
	
    tell_object(who, "%^BOLD%^%^WHITE%^Numerous %^BOLD%^%^BLACK%^"+
    "jagged spikes%^BOLD%^%^WHITE%^ jab out at you from "+
    TO->query_origin_object()+"%^BOLD%^%^WHITE%^!%^RESET%^");

    tell_room(env, "%^BOLD%^%^WHITE%^Numerous %^BOLD%^%^BLACK%^"+
    "jagged spikes%^BOLD%^%^WHITE%^ jab out at "+who->QCN+
    "%^BOLD%^%^WHITE%^ from "+TO->query_origin_object()+
    "!%^RESET%^", who);

    if(do_trap_save(who)) 
    {
        tell_object(who, "%^BOLD%^%^WHITE%^You manage to move in time "+
        "and are only hit by a few of the %^BOLD%^%^BLACK%^jagged spikes"+
        "%^BOLD%^%^WHITE%^!%^RESET%^");
		
        tell_room(env, who->QCN+"%^BOLD%^%^WHITE%^ manages to move in time "+
        "and is only hit by a few of the %^BOLD%^%^BLACK%^jagged spikes"+
        "%^BOLD%^%^WHITE%^!%^RESET%^", who);	

        do_trap_damage(who, 1);
        return;
    }
    else
    {
        tell_object(who, "%^BOLD%^%^WHITE%^You are unable to move in time "+
        "and the numerous spikes %^BOLD%^%^RED%^SINK"+
        "%^BOLD%^%^WHITE%^ painfully into your flesh!%^RESET%^");

        tell_room(env, who->QCN+"%^BOLD%^%^WHITE%^ is unable to move in time "+
        "and the numerous spikes %^BOLD%^%^RED%^SINK"+
        "%^BOLD%^%^WHITE%^ painfully into "+who->QP+
        " flesh!%^RESET%^", who);		
        do_trap_damage(who, 0);
        return;	
    }
    return;
}


