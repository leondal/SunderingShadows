#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int size;
int keepsize;

void create()
{
    ::create();
    set_spell_name("reduce person");
    set_spell_level(([ "mage" : 1, "magus" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS reduce person");
    set_description("When this spell is cast, humanoid caster will shrink twice in size. This spell will turn humans into halflings, firbolgs into humans. Halflings will turn into mice!

With this spell you gain size AC bonus, bonus to dexterity and penalty to strength.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


void spell_effect(int prof)
{
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

    tell_object(caster,"%^YELLOW%^You shrink twice in size!");
    tell_room(place,"%^YELLOW%^"+target->QCN+" shrinks twice in size!", caster );

    target->set_property("added short",({"%^YELLOW%^ (absurdly tiny)%^RESET%^"}));
    //For small characters the spell is cosmetic only
    keepsize = 0;
    size = caster->query_size();
    if (size > 0) {
        target->set_size_bonus(-1);
    } else {
        keepsize = 1;
    }
    target->set_property("spelled", ({TO}) );
    target->set_property("enlarged",1);
    target->add_ac_bonus(2);
    target->add_stat_bonus("strength",-2);
    target->add_stat_bonus("dexterity",2);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
}


void dest_effect()
{
    if(objectp(target))
    {
        if(!keepsize)
            target->set_size_bonus(0);
        target->add_ac_bonus(-2);
        target->add_stat_bonus("strength",2);
        target->add_stat_bonus("dexterity",-2);
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target, "%^YELLOW%^You grow back to normal!");
        tell_room(environment(target),"%^YELLOW%^"+target->QCN+" grows back to normal size.", target );
        target->remove_property("added short",({"%^YELLOW%^ (absurdly tiny)%^RESET%^"}));
        target->remove_property("enlarged");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
