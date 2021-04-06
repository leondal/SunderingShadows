#include <priest.h>
#include <daemons.h>
inherit SPELL;

int feattracker;

void create()
{
    ::create();
    set_spell_name("barkskin");
    set_spell_level(([ "ranger" : 2,"druid" : 2, "oracle":2]));
    set_mystery("nature");
    set_bonus_type("enhancement");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS barkskin");
    set_description("A ranger can attempt to take on part of a tree's nature, their skin hardening a little.  This spell "
        "does not stack with the damage resistance feat.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


int preSpell()
{
    if(member_array("damage resistance",(string*)caster->query_temporary_feats()) != -1)
    {
        tell_object(caster,"You are already under the influence of a similar effect.");
        return 0;
    }
    return 1;
}


string query_cast_string() { return "%^RED%^"+caster->QCN+" runs "+caster->QP+" hands over "+caster->QP+" arms."; }


void spell_effect(int prof)
{
    if (!objectp(caster))
    {
        dest_effect();
        return;
    }
    if (interactive(caster))
    {
        tell_object(caster, "%^ORANGE%^Your skin thickens and becomes rough, with a brittle texture like treebark!");
        tell_room(place,"%^ORANGE%^"+caster->QCN+"'s skin changes, becoming as rough and brittle as treebark!",caster);
    }
    if(member_array("damage resistance",(string*)caster->query_temporary_feats()) == -1)
    {
        caster->add_temporary_feat("damage resistance");
        feattracker = 1;
    }
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;
    set_end_time();
    call_out("dest_effect",spell_duration);
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^CYAN%^Your skin loses its brittle texture.%^RESET%^");
        if(feattracker == 1) caster->remove_temporary_feat("damage resistance");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
