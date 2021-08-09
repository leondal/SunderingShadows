// Stoneskin

#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <std.h>
inherit SPELL;

int mybonus;

void create() {
    ::create();
    set_spell_name("night armor");
    set_spell_level(([ "innate" : 4 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS night armor on TARGET");
    set_damage_desc("10 damage, cold and silver resistance");
    set_description("You entwine some of the energy from shadow plane into your target, strengthening their body. This spell won't work together with iron body or stone skin family of spells.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

int preSpell()
{
    if(!objectp(caster))
    {
        return 0;
    }
    if(!objectp(target))
    {
        tell_object(caster, "You must specify a target!");
        return 0;
    }
    if(target->query_stoneSkinned() || target->query_property("iron body"))
    {
        tell_object(caster,"That target already has protection of this nature!");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^"+target->QCN+"'s visage dims and turns black as the spell is muttered.";
}

void spell_effect(int prof)
{
    tell_object(caster,"%^BOLD%^%^BLACK%^You reach towards " +target->QCN + " infusing " + target->QO + " with darkness.");
    tell_object(target, "%^BOLD%^%^BLACK%^You sense darkness had entwined with your body, making it stronger!%^RESET%^");
    mybonus = clevel * 3 / 2;
    target->set_property("spelled",({TO}));
    target->set_property("damage resistance",10);
    target->set_resistance("silver",mybonus);
    target->set_resistance("cold",mybonus);
    target->set_property("iron body",1);
    addSpellToCaster();
    return;
}

void dest_effect() {
    if (!objectp(target)) {
      TO->remove();
      return;
    }
    tell_object(target,"%^BOLD%^%^BLACK%^The darkness within recedes, leaving you vulnerable once again.");
    target->set_property("damage resistance",-10);
    target->set_resistance("silver",-mybonus);
    target->set_resistance("cold",-mybonus);
    target->set_property("iron body",-1);
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
