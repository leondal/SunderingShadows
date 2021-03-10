#include <spell.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("boneshaker");
    set_spell_level(([ "mage" : 2, "cleric" : 2, "inquisitor":2 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS boneshaker on TARGET");
    set_damage_desc("untyped");
    set_description("Using a mental image of the target's skeleton, you shake it, causing the target to experience severe pain.");
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" makes a cage out of "+TP->QP+" fingers while chanting intently.%^RESET%^";
}

void spell_effect(int prof)
{
    spell_successful();
    tell_object(caster,"%^BOLD%^%^WHITE%^You will the crushing of "+target->QCN+"'s internals!");
    tell_room(place,"%^BOLD%^%^WHITE%^"+target->QCN+" staggers in pain!", ({caster, target}) );
    tell_object(target,"%^BOLD%^%^WHITE%^Your bones ache painfully as the spell hits you!");
    damage_targ(target, target->return_target_limb(), sdamage,"untyped");
    spell_successful();
    TO->dest_effect();
}
