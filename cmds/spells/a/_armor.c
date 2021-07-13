//      Armor
//      Thorn@Shadowgate w/ lots of help from Melnmarn
//      1/19/95
//      Wizard Spells
//      armor.c
//      Modified and updated by Vashkar
#include <spell.h>
#include <daemons.h>
inherit SPELL;

int benchmark,tally,bonus;


void create()
{
    ::create();
    set_spell_name("armor");
    set_spell_level(([ "mage" : 1, "magus" : 1, "oracle" : 1 ]));
    set_mystery("spellscar");
    set_bonus_type("armor");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS armor [on TARGET]");
    set_description("When armor is cast on someone, they will receive an AC bonus of 4. This bonus will only be "
        "valid while not wearing armor of any type. Clothing is not considered armor.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([ "mage" : ([ "blessed leather" : 1, ]), ]));
    set_property("keywords", ({ "defensive", "targeted", "personal" }));
    set_helpful_spell(1);
}

int preSpell()
{
    if (!target) target = caster;
    /*
    if(target->query_property("armoured"))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^You feel your spell repelled...");
        return 0;
    }
    */
    return 1;
}

void spell_effect(int prof)
{
    bonus = 4;

    if (!target) target = caster;

    if (!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }

    benchmark = target->query_hp();
    tally = 0;

    if (!target->is_ok_armour("mage"))
    {
        tell_object(caster,"The spell can not offer protection to those wearing armor.");
        if(objectp(TO)) { TO->remove(); }
        return;
    }

    spell_successful();

    if (target == caster)
    {
        tell_object(caster,"%^BOLD%^%^CYAN%^A magical shield shimmers around you as "
            "the leather vanishes from your hand!");
        tell_room(place,"%^BOLD%^%^CYAN%^A magical shield shimmers around "
            ""+caster->QCN+" as the leather vanishes from "+caster->QP+" "
            "hand!.", caster );
    }

    else
    {
        tell_object(caster,"%^BOLD%^%^CYAN%^A magical shield shimmers around "
            ""+target->QCN+" as the leather vanishes from your hand!");
        tell_object(target,"%^BOLD%^%^CYAN%^A magical shield shimmers around you as "
            "the leather vanishes from "+caster->QP+" hand!.");
        tell_room(place,"%^BOLD%^%^CYAN%^A magical shield shimmers around "+target->QCN+" "
            "as the leather vanishes from "+caster->QCN+"'s hand!.",({caster, target}) );
    }

    target->add_ac_bonus(bonus);
    target->set_property("spelled", ({TO}) );
    //target->set_property("armoured",1);
    addSpellToCaster();
    call_out("test", 7);
}


void test()
{
    int max_damage, add_tally, thp;

    if (!objectp(target))
    {
        remove();
        return;
    }

    if (!target->is_ok_armour("mage"))
    {
        tell_object(caster,"The spell can not offer protection to those wearing armor.");
        TO->dest_effect();
        return;
    }

    if (!objectp(target))
    {
        dest_effect();
        return;
    }

    call_out("test", 7);
    return 0;
}


void dest_effect()
{
    if (find_call_out("test") != -1) remove_call_out("test");

    if(objectp(target))
    {
        target->add_ac_bonus(-1 * bonus);
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target, "%^CYAN%^The magic shielding around you glows briefly, then fades away.");
        tell_room(environment(target),"%^CYAN%^"+target->QCN+" glows briefly.", target );
        //target->remove_property("armoured");
    }

    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


string query_cast_string() { return "%^CYAN%^"+caster->QCN+" holds up a piece of leather in the air."; }
