#include <spell.h>
#include <clock.h>
#include <magic.h>
inherit SPELL;

int abonus;
int rbonus; //Should make evasion useful, but not above that
int nodeathflag = 0; //To make spell useful on targets already warded against death
int duration;

void create() {
    ::create();
    set_spell_name("psionic foresight");
    set_spell_level(([ "psion" : 9 ]));
    set_spell_sphere("clairsentience");
    set_bonus_type("insight");
    set_syntax("cast CLASS psionic foresight [on TARGET]");
    set_damage_desc("+2 to armor bonus, +2 to reflex save, death ward feat");
    set_description("The manifester uses this spell to heighten their awareness for a time, allowing them to perceive fragments of their immediate future. This allows them to react pre-emptively to many threats, defending better against attacks that they can see coming before they actually land, and they may even be able avoid the death itself.");
    set_verbal_comp();
    set_somatic_comp();
    set_property("keywords", ({ "defensive", "personal", "targeted"}));
    set_helpful_spell(1);
}

int preSpell()
{
    if (!target) target = caster;
    /*
    if(target->query_property("foresighted"))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^You feel your spell repelled...");
        return 0;
    }
    */
    return 1;
}

void spell_effect(int prof)
{

    duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 7;
    abonus = 2;
    //abonus = 1 + (clevel / 16);
    rbonus = 2;
    //rbonus = 1 + (clevel / 12);

    if (!target)
        target = caster;

    if (!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }

    if (target->query_property("foresighted"))
    {
        tell_object(caster,"%^CYAN%^The spell is repelled by its own magic.%^RESET%^\n");
        TO->remove();
    }

    spell_successful();

    if (target == caster)
    {
        tell_object(caster,"%^CYAN%^You feel the very future itself.\n");
        tell_room(place,"%^CYAN%^"+caster->QCN+" opens and closes their eyes, looking distanced from the surroundings.\n", caster );
    }
    else
    {
        tell_object(target,"%^CYAN%^You feel the very future itself.\n");
        tell_room(place,"%^CYAN%^"+target->QCN+" opens and closes their eyes, looking distanced from the surroundings.\n", target );

    }
    target->add_ac_bonus(abonus);
    target->add_saving_bonus("reflex",rbonus);
    target->set_property("spelled", ({TO}) );
    if(member_array("death ward",(string*)target->query_temporary_feats()) == -1) {
        target->add_temporary_feat("death ward");
        nodeathflag = 1;
    }

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
        if(nodeathflag)
            target->remove_temporary_feat("death ward");
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target, "%^CYAN%^The future no longer is present in your mind.");
    }

    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() { return "%^CYAN%^"+caster->QCN+" holds and disappears two pearls into non-existence."; }
