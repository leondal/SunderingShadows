#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

int bonus, duration;

void create()
{
    ::create();
    set_spell_name("path of shadow");
    set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS path of shadow");
    set_damage_desc("Fast Healing 2 on caster");
    set_description("The Shadows, bringer of death, but also the embrace of a dark mother. Feed upon the shadows and find yourself nourished.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
	set_helpful_spell(1);
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

string query_casting_string()
{
    return "%^BOLD%^%^BLACK%^" + caster->QCN + " puts their hands together where e%^RESET%^%^GREEN%^l%^BOLD%^d%^RESET%^r%^BOLD%^i%^BLACK%^tch e%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^r%^BOLD%^g%^BLACK%^y f%^RESET%^%^GREEN%^o%^BOLD%^r%^RESET%^m%^BOLD%^s%^BLACK%^.";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("fast_healing_spell"))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^You feel your spell repelled...");
        return 0;
    }
    return 1;
}

void spell_effect()
{

    if(!objectp(caster))
    {
        TO->remove();
        return;
    }

    tell_room(place,"%^BOLD%^%^BLACK%^The surrounding shadows feed "+caster->QCN+"'s body.");

    duration = clevel * ROUND_LENGTH * 10;
    tell_object(caster,"%^BOLD%^%^BLACK%^You feel emboldened by the shadows around you.");
    caster->set_property("spelled",({TO}));
    caster->set_property("fast healing",2);
    caster->set_property("fast_healing_spell",1);
    spell_successful();
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^BOLD%^%^BLACK%^The elation you felt begins to ebb as the shadows around you dissappate.%^RESET%^");
        target->remove_property_value("spelled", ({TO}) );
        target->set_property("fast healing",-2);
        target->remove_property("fast_healing_spell");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
