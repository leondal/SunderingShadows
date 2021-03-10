#include <std.h>
#include <daemons.h>
#include "traps.h"
inherit TRAP_INH;

void create()
{
    ::create();
    set_damage_type("acid");
    set_my_trap_name("acid");
    set_my_die(6);	
    set("lore_string", "%^BOLD%^%^GREEN%^This trap was designed with "+
    "the intention of covering multiple targets in highly potent acid.%^RESET%^");
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

        tell_object(vics[x], "%^BOLD%^%^GREEN%^Acid splashes out at "+
        "you from "+TO->query_origin_object()+"%^BOLD%^%^GREEN%^!%^RESET%^");

        tell_room(env, "%^BOLD%^%^GREEN%^Acid splashes out at "+    
        vics[x]->QCN+"%^BOLD%^%^GREEN%^ from "+TO->query_origin_object()+
        "!", vics[x]);

        if(do_trap_save(vics[x])) 
        {
            tell_object(vics[x], "%^BOLD%^%^GREEN%^You manage to move "+
            "out of the way just in time to avoid most of the "+
            "acid.%^RESET%^");
			
            tell_room(env, vics[x]->QCN+ "%^BOLD%^%^GREEN%^ manages to "+
            "move out of the way just in time, avoiding most of the "+
            "acid.%^RESET%^", vics[x]);
			
            do_trap_damage(vics[x], 1);
            continue;
        }
        else
        {
            tell_object(vics[x], "%^BOLD%^%^GREEN%^You are unable to move "+
            "out of the way in time and are covered in acid!%^RESET%^");
			
            tell_room(env, vics[x]->QCN+"%^BOLD%^%^GREEN%^ is unable to move "+ 
            "out of the way in time and is covered in acid!%^RESET%^", vics[x]);

            do_trap_damage(vics[x], 0);     
            continue;
        }
    }
    return;
}