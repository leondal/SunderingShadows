#include <std.h>
#include <daemons.h>
#include <spell.h>
inherit SPELL;

int bonus;

void create() {
    ::create();
    set_spell_name("aid");
    set_spell_level(([ "cleric" : 2, "inquisitor" : 2 ,]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS aid [on TARGET]");
    set_damage_desc("clevel + 10 max hitpoints bonus, +1 to all saves");
    set_description("With this spell, the caster harnesses the flow of negative energies to grant herself a limited ability to avoid death. While this spell is active, the caster is healthier.");
	set_helpful_spell(1);
}

int query_fl_power()
{
    return 1;
}

string query_casting_string()
{
    return "%^BLUE%^With a shout and a body wide flex, "+caster->QCN+" starts to cast a spell.";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("spell_bonus_hp"))
    {
        tell_object(caster,"The spell is repelled by similar magic.");
        TO->remove();
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

    if (caster == target) {
        tell_object(caster,"%^RED%^You slowly summon inner strength, lending the force of your will to the strength of your body.");
        tell_room(environment(caster),"%^RED%^You see a wave of force surround and strengthen "+caster->QCN+"'s body.",({caster}));
    }
    else
    {
        tell_object(caster,"%^RED%^You slowly summon inner strength, lending the force of your will to strengthen "+target->QCN+"'s body.");
        tell_object(target,"%^RED%^You feel the force of "+caster->QCN+"'s will strengthen your body.");
        tell_room(environment(caster),"%^RED%^You see a wave of force surround and strengthen "+target->QCN+"'s body.",({target}));
    }
    bonus = query_fl_power()*clevel;
    target->add_max_hp_bonus(bonus + 10);
    target->set_property("spelled",({TO}));
    target->set_property("spell_bonus_hp",1);
    target->add_saving_bonus("all",1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(target))
    {
       target->add_max_hp_bonus(-bonus-10);
       target->remove_property_value("spelled", ({TO}) );
       target->remove_property("spell_bonus_hp");
       target->add_saving_bonus("all",-1);
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
