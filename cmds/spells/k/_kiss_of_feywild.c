#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("kiss of feywild");
    set_spell_level(([ "druid" : 4, "bard" : 4, "ranger" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS kiss of feywild [on TARGET]");
    set_damage_desc("on living, fast healing 2");
    set_description("Lo, Their Endless Host, the Harbingers of Life, Mercy and Kindness Followed Where'er She Walked, Where Her Court Will be Held.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
	set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^GREEN%^With %^CYAN%^b%^BOLD%^ou%^RESET%^%^CYAN%^n%^BOLD%^d%^RESET%^%^CYAN%^l%^BOLD%^es%^RESET%^%^CYAN%^s %^MAGENTA%^j%^BOLD%^o%^RESET%^%^MAGENTA%^y %^GREEN%^a song of l%^BOLD%^if%^RESET%^%^GREEN%^e is sang.%^WHITE%^";
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
    if(!target)
        target = caster;

    if(!objectp(target))
    {
        TO->remove();
        return;
    }
    if(!objectp(caster))
    {
        TO->remove();
        return;
    }

    tell_room(place,"%^BOLD%^%^GREEN%^A song of life embraces "+target->QCN+"'s body.");
    if(target->is_undead())
    {
        tell_object(target,"%^BOLD%^%^BLACK%^BUT JOY IS %^WHITE%^NOT%^BLACK%^ YOUR WAY%^RESET%^");
        tell_object(caster,"%^BOLD%^%^BLACK%^You feel your spell repelled...%^RESET%^");
        TO->remove();
    }
    else
    {
        int duration = clevel * ROUND_LENGTH * 10;
        tell_object(target,"%^BOLD%^%^GREEN%^You feel more healthy and joyful.");
        target->set_property("spelled",({TO}));
        target->set_property("fast healing",2);
        target->set_property("fast_healing_spell",1);
        spell_successful();
        addSpellToCaster();
        spell_duration = duration;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^BOLD%^%^GREEN%^The elation you felt begins to ebb as life's realities return.%^RESET%^");
        target->remove_property_value("spelled", ({TO}) );
        target->set_property("fast healing",-2);
        target->remove_property("fast_healing_spell");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
