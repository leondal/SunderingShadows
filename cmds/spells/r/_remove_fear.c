#include <std.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("remove fear");
    set_spell_level(([ "cleric" : 1, "bard" : 1, "inquisitor" : 1 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS remove fear [on TARGET]");
    set_damage_desc("removes cowering, frightened, panicked, shaken");
    set_description("This spell will boost morale and will remove some fear effects.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

spell_effect()
{
    object * effects;
    if(!objectp(target))
        target = caster;

    if(target!=caster)
    {
        tell_object(caster,"%^GREEN%^You enspell words of support, lifting all of "+target->QCN+" fears!");
        tell_room(place,"%^GREEN%^"+caster->QCN+" enspells words of support at "+target->QCN+"!",caster);
        tell_object(target,"%^GREEN%^You feel all your fears disappear!");
    }
    else
    {
        tell_object(caster,"%^GREEN%^You concentrate and lift all own fears.");
    }

    effects = target->query_property("status_effects");

    if(sizeof(effects))
    {
        object effect;
        foreach(effect in effects)
        {
            if(!objectp(effect))
                continue;

            if(effect->query_name() == "effect_cowering" ||
               effect->query_name() == "effect_frightened" ||
               effect->query_name() == "effect_panicked" ||
               effect->query_name() == "effect_shaken")
                effect->dest_effect();
        }
    }

}
