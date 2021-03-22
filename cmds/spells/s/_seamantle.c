#include <spell.h>
#include <clock.h>
#include <magic.h>
inherit SPELL;

int abonus;
int rbonus;
int nodeathflag = 0;
int duration;

void create() {
    ::create();
    set_spell_name("seamantle");
    set_spell_level(([ "mage" : 8, "druid" : 8, "oracle" : 8, "cleric" : 8 ]));
    set_domains("water");
    set_mystery("waves");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS seamantle");
    set_damage_desc("8 to AC, 4 to reflex save");
    set_description("You surround yourself with column of water, or control currents of water you're already in, to shield yourself from harm. Such mantle is powerful shield, yet maintaining it for long periods of time is nearly impossible even for an experienced caster.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
    if (caster->query_property("seamantled"))
    {
        tell_object(caster,"%^CYAN%^The spell is repelled by its own magic.%^RESET%^\n");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{

    duration = (clevel/2+4)*ROUND_LENGTH;
    abonus = 8;
    rbonus = 4;

    target = caster;

    if (target->query_property("seamantled"))
    {
        tell_object(caster,"%^CYAN%^The spell is repelled by its own magic.%^RESET%^\n");
        TO->remove();
    }

    spell_successful();

    tell_object(caster,"%^CYAN%^%^BOLD%^Currents of water rise around you in a stormy helix.");
    tell_room(place,"%^BOLD%^%^CYAN%^Currents of water rise around "+caster->QCN+" in a stormy helix.", caster );

    target->add_ac_bonus(abonus);
    target->add_saving_bonus("reflex",rbonus);
    target->set_property("spelled", ({TO}) );

    target->set_property("seamantled",1);
    target->set_property("added short",({"%^BOLD%^%^CYAN%^ (surrounded by helix of water)%^RESET%^"}));
    addSpellToCaster();
    call_out("test", 10);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void test()
{
    if (!objectp(target))
    {
        remove();
        return;
    }

    if (!objectp(target))
    {
        dest_effect();
        return;
    }

    call_out("test", 10);
    return 0;
}

void dest_effect()
{
    if (find_call_out("test") != -1) remove_call_out("test");

    if(objectp(target))
    {
        target->add_ac_bonus(- abonus);
            target->add_saving_bonus("reflex",- rbonus);
        target->remove_property_value("spelled", ({TO}) );
        target->remove_property_value("added short",({"%^BOLD%^%^CYAN%^ (surrounded by helix of water)%^RESET%^"}));
        tell_object(target, "%^BOLD%^%^CYAN%^The seamantle fades out.");
        tell_room(ENV(target),"%^BOLD%^%^CYAN%^Currents of water around "+caster->QCN+" fade out.", target );
        target->remove_property("seamantled");
    }

    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
