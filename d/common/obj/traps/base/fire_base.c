#include <std.h>
#include <daemons.h>
#include "traps.h"
inherit TRAP_INH;

void create()
{
    ::create();
    set_damage_type("fire");
    set_my_trap_name("fire");
    set_my_die(8);	
    set("lore_string", "%^BOLD%^%^RED%^This trap was designed with "+
    "the intention of unleashing a blast of fire onto a single target.");
    set_can_deflect(1);
}

void trap_activated(object who)
{
    object env;
    int x, dam;
    if(!objectp(TO)) return;
    if(!objectp(who)) return;
    if(!objectp(environment(who))) return;
    env = environment(who);
	
    tell_object(who, "%^BOLD%^%^RED%^A ball of f%^BOLD%^%^YELLOW%^i"+
    "%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^e%^BOLD%^%^RED%^ shoots out at "+
    "you from "+TO->query_origin_object()+"%^BOLD%^%^RED%^!%^RESET%^");
	
    tell_room(env, "%^BOLD%^%^RED%^A ball of f%^BOLD%^%^YELLOW%^i"+
    "%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^e%^BOLD%^%^RED%^ shoots out at "+
    who->QCN+"%^BOLD%^%^RED%^ from "+TO->query_origin_object()+
    "!", who);

    if(do_trap_save(who)) 
    {
        tell_object(who, "%^BOLD%^%^RED%^You manage to move in time "+
        "and are only %^BOLD%^%^YELLOW%^SINGED%^BOLD%^%^RED%^ by the "+
        "ball of f%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^r%^BOLD%^"+ 
        "%^YELLOW%^e%^BOLD%^%^RED%^!%^RESET%^");
		
        tell_room(env, who->QCN+"%^BOLD%^%^RED%^ manages to move in time "+ 
        "and is only %^BOLD%^%^YELLOW%^SINGED%^BOLD%^%^RED%^ by the "+
        "ball of f%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^r%^BOLD%^"+ 
        "%^YELLOW%^e%^BOLD%^%^RED%^!%^RESET%^", who);
		
        do_trap_damage(who, 1);
        return;
    }
    else
    {
        tell_object(who, "%^BOLD%^%^RED%^You are unable to move in time "+
        "and are %^YELLOW%^BURNED%^BOLD%^%^RED%^ by the ball of "+
        "f%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^e%^BOLD%^%^RED%^"+
        "!%^RESET%^");

        tell_room(env, who->QCN+"%^BOLD%^%^RED%^ is unable to move in time "+
        "and is %^BOLD%^%^YELLOW%^BURNED%^BOLD%^%^RED%^ by the ball of "+
        "f%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^e%^BOLD%^%^RED%^"+
        "!%^RESET%^", who);
		
        do_trap_damage(who, 0);
        return;	
    }
    return;
}


