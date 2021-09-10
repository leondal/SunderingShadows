#include <spell.h>
inherit SPELL;

#define TRACEOBJ "/d/magic/obj/trace_teleport"

void create()
{
    ::create();
    set_spell_name("trace psychoport");
    set_spell_level(([ "psion" : 4 ]));
    set_spell_sphere("psychoportation");
    set_syntax("cast CLASS trace psychoport");
    set_description("This spell allows a psionic manifester to trace any recent teleportation from or out of the area and memorize the source or destination. This spell won't work on portal-like sources of travel.");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + caster->QCN + " closes the eyes and concentrates.%^RESET%^";
}

void spell_effect()
{
    object trace, obj;
    string fname;

    spell_successful();
    if (!objectp(trace = place->query_property("recent teleport"))) {
        tell_object(caster,"%^BOLD%^%^WHITE%^You fail to find any teleportation traces.");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^RED%^You sense there was a recent teleport from or into%^RESET%^ " + trace->query_short());
    obj = new(TRACEOBJ);
    obj->setup_mem(file_name(trace), caster);
    obj->move(caster);
    dest_effect();
}
