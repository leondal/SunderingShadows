#include <std.h>
#include <daemons.h>
#include "traps.h"
inherit TRAP_INH;

void create()
{
    ::create();
    set_damage_type("trip");
    set_my_trap_name("entangle");
    set("stun_message", "%^BOLD%^%^GREEN%^You are held fast by the "+
    "viney tentacles!%^RESET%^");

    set("lore_string", "%^BOLD%^%^GREEN%^This trap was designed with "+
    "the intention of tripping up and holding multiple targets.%^RESET%^");
    set_my_die(1);	
}

void trap_activated(object who)
{
    object *vics, env;
    int x, dam;
    if(!objectp(TO)) return;
    if(!objectp(who)) return;
    if(!objectp(environment(who))) return;
    env = environment(who);
    vics = all_living(env);
    vics = filter_array(vics, "is_non_immortal", FILTERS_D);
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) return;

        tell_object(vics[x], "%^BOLD%^%^GREEN%^A mass of viney tentacles "+
        "jump out from "+TO->query_origin_object()+"%^BOLD%^%^GREEN%^ "+
        "and grab at you!%^RESET%^");

        tell_room(env, "%^BOLD%^%^GREEN%^A mass of viney tenacles jump out "+
        "from "+TO->query_origin_object()+ "%^BOLD%^%^GREEN%^ and grab at "+
        vics[x]->QCN+"%^BOLD%^%^GREEN%^!%^RESET%^", vics[x]);

        if(do_trap_save(vics[x])) 
        {
            tell_object(vics[x], "%^BOLD%^%^GREEN%^You are able to move out "+
            "of the way just in time and only a few of the tentacles manage "+
            "to %^RESET%^%^GREEN%^LATCH%^BOLD%^%^GREEN%^ onto your "+
            "legs!%^RESET%^");
						
            tell_room(env, vics[x]->QCN+ "%^BOLD%^%^GREEN%^ is able to move out "+
            "of the way just in time and only a few of the tentacles "+
            "%^RESET%^%^GREEN%^LATCH%^BOLD%^%^GREEN%^ onto "+vics[x]->QP+
            " legs.%^RESET%^", vics[x]);
			
            do_trap_damage(vics[x], 1, "tripped");
            continue;
        }
        else
        {
            tell_object(vics[x], "%^BOLD%^%^GREEN%^You are unable to move "+
            "out of the way in time and the mass of viney tentacles %^RESET%^"+
            "%^GREEN%^WRAPS%^BOLD%^%^GREEN%^ tightly around your legs!%^RESET%^");
			
            tell_room(env, vics[x]->QCN+"%^BOLD%^%^GREEN%^ is unable to move "+
            "out of the way in time and the mass of viney tentacles "+
            "%^RESET%^%^GREEN%^WRAPS%^BOLD%^%^GREEN%^ tightly around "+
            vics[x]->QP+"%^BOLD%^%^GREEN%^ legs!%^RESET%^", vics[x]);

            do_trap_damage(vics[x], 0, "tripped");
            continue;
        }
    }
    return;
}


