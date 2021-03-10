#include <std.h>
#include <daemons.h>
#include "traps.h"
inherit TRAP_INH;

void create()
{
    ::create();
    set_damage_type("electricity");
    set_my_trap_name("lightning");
    set_my_die(6);	
    set("lore_string", "%^BOLD%^%^YELLOW%^This trap was designed with "+
    "the intention of releasing a powerful jolt of electricity onto "+
    "multiple targets.%^RESET%^");
    set_can_deflect(1);
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

        tell_object(vics[x], "%^BOLD%^%^YELLOW%^A bolt of lightning arcs out "+
        "from "+TO->query_origin_object()+"%^BOLD%^%^YELLOW%^ "+
        "streaks toward you!%^RESET%^");

        tell_room(env, "%^BOLD%^%^YELLOW%^A bolt of lightning arcs out from "+
        " "+TO->query_origin_object()+ "%^BOLD%^%^YELLOW%^ and streaks toward "+
        vics[x]->QCN+"%^BOLD%^%^YELLOW%^!%^RESET%^", vics[x]);

        if(do_trap_save(vics[x])) 
        {
            tell_object(vics[x], "%^BOLD%^%^YELLOW%^You are able to move out "+
            "of the way just in time and the bolt of lightning only "+
            "%^BOLD%^%^BLACK%^GRAZES%^BOLD%^%^YELLOW%^ you!%^RESET%^");
			
            tell_room(env, vics[x]->QCN+ "%^BOLD%^%^YELLOW%^ is able to move out "+
            "of the way just in time and the bolt of lightning only "+
            "%^BOLD%^%^BLACK%^GRAZES%^BOLD%^%^YELLOW%^ "+vics[x]->QO+
            ".%^RESET%^", vics[x]);
			
            do_trap_damage(vics[x], 1); 
            continue;
        }
        else
        {
            tell_object(vics[x], "%^BOLD%^%^YELLOW%^You are unable to move "+
            "out of the way in time and the bolt of lightning %^BOLD%^%^RED%^"+
            "SLAMS%^BOLD%^%^YELLOW%^ into your chest!%^RESET%^");
			
            tell_room(env, vics[x]->QCN+"%^BOLD%^%^YELLOW%^ is unable to move "+
            "out of the way in time and the bolt of lightning %^BOLD%^%^RED%^"+
            "SLAMS%^BOLD%^%^YELLOW%^ into "+vics[x]->QP+
            " chest!%^RESET%^", vics[x]);

            do_trap_damage(vics[x], 0);
            continue;
        }
    }
    return;
}


