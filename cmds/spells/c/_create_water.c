// Modified by Pator@Shadowgate
// AUgust 25 1995
// Remodified 11/2/95 by Pator@shadowgate

#include <priest.h>
inherit SPELL;

object drinks, where;


create()
{
    ::create();
    set_author("pator");
    set_spell_name("create water");
    set_spell_level(([ "cantrip" : 1, "paladin" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS create water");
    set_description("This spell creates a pool of drinkable water. You can drink from the pool, to quench your thirst.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


int preSpell()
{
    if (present("pool of water", place))
    {
        tell_object(caster, "There is already a pool of water here.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    int duration, amount;

    if( interactive(caster) )
    {
        set_verbal_comp();
        set_somatic_comp();
        tell_object(caster, "You create a pool of clean water.");
        tell_room(place, YOU+" makes a pool of water.", caster);
        drinks= new("/cmds/priest/obj/water.c");
        where = environment(caster);
    }
    else
    {
        tell_room(place, YOU+" conjures a puddle of clean water.", ({ caster}));
        drinks= new("/cmds/priest/obj/water.c");
        where = place;
    }

    amount = clevel/2;
    amount++;
    drinks->set_drinks(amount);
    drinks->move(where);
    drinks->set_property("spelled", ({TO}) );
    where->set_property("fill waterskin", 1);

    duration = clevel * 60;

    spell_successful();
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}


void dest_effect()
{
    if (objectp(drinks))
    {
        drinks->remove();
        tell_room(ROOM,"The pool of water just vanishes!");
    }
    if(objectp(where)) {
        where->set_property("fill waterskin", -1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() { return "%^BOLD%^%^CYAN%^"+YOU+" focuses on a bit of water and chants softly.\n"; }
