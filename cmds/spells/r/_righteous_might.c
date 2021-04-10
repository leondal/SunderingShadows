#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int size;

void create()
{
    ::create();
    set_spell_name("righteous might");
    set_spell_level(([ "cleric" : 5, "inquisitor" : 5, "oracle" : 5 ]));
    set_mystery("battle");
    set_bonus_type("size");
    set_spell_sphere("alteration");
    set_domains("strength");
    set_syntax("cast CLASS righteous might");
    set_description("Your height immediately doubles, and your weight increases by a factor of eight. This increase changes your size category to the next larger one. You gain a +4 size bonus to Strength and Constitution and take a -2 penalty to your Dexterity. You gain natural armor bonus of 2. Any equipment you wear will grow with you as long as you wear it.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


void spell_effect(int prof)
{
    if(!target)
        target = caster;

    if (target->query_property("enlarged"))
    {
        tell_object(caster,"The spell is repelled by its own magic.");
        TO->remove();
    }

    if(target->query_size_bonus())
    {
        tell_object(caster,"The spell is repelled by similar magic.");
        TO->remove();
    }

    spell_successful();

    tell_object(target,"%^RED%^You grow twice in size and feel more powerful!");
    tell_room(place,"%^RED%^"+target->QCN+" grows twice in size!", target);

    target->set_property("added short",({"%^RED%^ (giant)%^RESET%^"}));
    target->set_size_bonus(1);
    target->add_ac_bonus(2);
    target->add_stat_bonus("strength",4);
    target->add_stat_bonus("constitution",4);
    target->add_stat_bonus("dexterity",-2);
    target->set_property("spelled", ({TO}) );
    target->set_property("enlarged",1);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
}


void dest_effect()
{
    if(objectp(target))
    {
        target->set_size_bonus(0);
        target->add_ac_bonus(-2);
        target->remove_property_value("spelled", ({TO}) );
        target->add_stat_bonus("strength",-4);
        target->add_stat_bonus("constitution",-4);
        target->add_stat_bonus("dexterity",2);
        tell_object(target, "%^RED%^You shrink back to normal!");
        tell_room(environment(target),"%^RED%^"+target->QCN+" shrinks back to normal size.", target );
        target->remove_property_value("added short",({"%^RED%^ (giant)%^RESET%^"}));
        target->remove_property("enlarged");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
