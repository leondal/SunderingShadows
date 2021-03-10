#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <magic_effects.h>
inherit SPELL;

int counter = 0;

void create()
{
    ::create();
    set_spell_name("litany of weakness");
    set_spell_level(([ "paladin" : 1,"inquisitor":1 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS litany of weakness TARGET");
    set_damage_desc("fatigue");
    set_description("Your litany proclaims your target weak, sapping its strength. The target is fatigued for 3 rounds. While subject to this spell, the target cannot be the target of another spell that has the word 'litany' in the title..");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^BLUE%^A dark aura threads its way around "+caster->QCN+" intones a spell.%^RESET%^";
}

void spell_effect(int prof)
{
    if(!objectp(target))
        dest_effect();
    if(target->query_property("litany"))
    {
        tell_object(caster,"%^BOLD%^They are already under effects of the litany!");
    }
    tell_object(caster,"%^BLUE%^You send the dark aura towards "+target->QCN+"!");
    tell_room(place,"%^BLUE%^"+caster->QCN+" sends the dark aura towards "+target->QCN+"!",caster);

    "/std/effect/status/fatigued"->apply_effect(target,3);

    target->set_property("litany",1);
    spell_successful();
}


void dest_effect()
{
    if(objectp(target))
        target->remove_property("litany");
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
