#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int size;

void create()
{
    ::create();
    set_spell_name("enlarge person");
    set_spell_level(([ "mage" : 1, "oracle" : 1, "magus" : 1, "cleric" : 1 ]));
    set_spell_sphere("alteration");
    set_domains("strength");
    set_mystery("battle");
    set_bonus_type("size");
    set_syntax("cast CLASS enlarge person");
    set_description("When this spell is cast, the humanoid caster will grow twice in size. This spell will turn halflings into humans, humans into firbolgs, and firbolgs into mountains.

With this spell you gain a bonus to constitution and strength, and a penalty to AC and dexterity.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


void spell_effect(int prof)
{
    target = caster;

    /*
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
    */

    spell_successful();

    tell_object(target,"%^YELLOW%^You grow twice in size!");
    tell_room(place,"%^YELLOW%^"+target->QCN+" grows twice in size!", target);

    target->set_property("added short",({"%^YELLOW%^ (gigantic)%^RESET%^"}));
    target->set_size_bonus(1);
    target->add_ac_bonus(-2);
    target->add_stat_bonus("strength",2);
    target->add_stat_bonus("constitution",2);
    target->add_stat_bonus("dexterity",-2);
    target->set_property("spelled", ({TO}) );
    //target->set_property("enlarged",1);
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
        target->add_ac_bonus(2);
        target->remove_property_value("spelled", ({TO}) );
        target->add_stat_bonus("strength",-2);
        target->add_stat_bonus("constitution",-2);
        target->add_stat_bonus("dexterity",2);
        tell_object(target, "%^YELLOW%^You shrink back to normal!");
        tell_room(environment(target),"%^YELLOW%^"+target->QCN+" shrinks back to normal size.", target );
        target->remove_property("added short",({"%^YELLOW%^ (gigantic)%^RESET%^"}));
        //target->remove_property("enlarged");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
