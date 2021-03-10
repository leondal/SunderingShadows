#include <spell.h>
#include <magic.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("boneshatter");
    set_spell_level(([ "mage" : 4, "cleric" : 4, "oracle" : 4 ]));
    set_spell_sphere("necromancy");
    set_mystery("bones");
    set_syntax("cast CLASS boneshatter on TARGET");
    set_damage_desc("untyped, exhausted or fatigued on save");
    set_description("With your mere will, you splinter your enemy's skeleton. The enemy fights the change, and if they fail they will become exhausted, taking damage to their strength and dexterity. If they successfully overcome the pain, they instead become fatigued for a short while. This spell will work only on living beings, and will cause stat damage just once per target.");
    set_save("fort");
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" makes a cage out of "+TP->QP+" fingers while chanting intently.%^RESET%^";
}

void spell_effect(int prof)
{
    int duration;
    spell_successful();
    tell_object(caster,"%^BOLD%^%^WHITE%^You will the crushing of "+target->QCN+"'s internals!");
    tell_room(place,"%^BOLD%^%^WHITE%^"+target->QCN+" staggers as you hear a crushing sound!", ({caster, target}) );
    tell_object(target,"%^BOLD%^%^WHITE%^Your bones ache painfully as the spell hits you!");
    damage_targ(target, target->return_target_limb(), sdamage,"untyped");
    duration = clevel/4+1;

    if(do_save(target,0))
        "/std/effect/status/fatigued"->apply_effect(target,duration);
    else
        "/std/effect/status/exhausted"->apply_effect(target,duration);

    spell_successful();
}
