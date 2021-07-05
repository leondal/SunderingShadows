#include <std.h>
#include <magic.h>
inherit SPELL;

int tracker;

void create()
{
    ::create();
    set_spell_name("aspect of the wolf");
    set_spell_level(([ "druid" : 5, "ranger" : 4, "oracle" : 5 ]));
    set_mystery("lunar");
    set_spell_sphere("alteration");
    set_bonus_type("enhancement");
    set_syntax("cast CLASS aspect of the wolf");
    set_damage_desc("+4 to str and dex, knockdown feat");
    set_description("Feel the aspect of the wolf boiling though your blood.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    tell_object(caster, "%^GREEN%^The nature's power thunders in your blood as you hum. ");
    tell_room(place, "%^GREEN%^" + caster->QCN + " begins to hum.", caster);
    return "display";
}

int preSpell()
{
    
    if (caster->query_property("aspect of the wolf") || caster->query_property("augmentation")) {
        tell_object(caster, "You already have this spell active.");
        return 0;
    }
    
    return 1;
}

void spell_effect(int prof)
{
    tell_room(place, "%^GREEN%^" + caster->QCN + " chants the lyrics of a " + "melodic prayer. Suddenly, " + caster->QP + " eyes brighten with silhouette of the moon.", caster);
    tell_object(caster, "%^GREEN%^You feel the hunt filling your mind.");

    caster->set_property("aspect of the wolf", 1);
    //caster->set_property("augmentation", 1);
    caster->add_stat_bonus("strength", 4);
    caster->add_stat_bonus("dexterity", 4);
    if (member_array("knockdown", (string*)caster->query_temporary_feats()) == -1) {
        caster->add_temporary_feat("knockdown");
        tracker = 1;
    }
    caster->set_property("spelled", ({ TO }));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
}

void dest_effect()
{
    if (objectp(caster)) {
        caster->remove_property("aspect of the wolf");
        //caster->remove_property("augmentation");
        caster->add_stat_bonus("strength", -4);
        caster->add_stat_bonus("dexterity", -4);
        tell_object(caster, "%^GREEN%^%^BOLD%^The feeling of the hunt leaves you.");
        if (tracker == 1) {
            caster->remove_temporary_feat("knockdown");
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
