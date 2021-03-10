#include <std.h>
#include <magic.h>
inherit SPELL;

int trackera, trackerb;

void create()
{
    ::create();
    set_spell_name("wieldskill");
    set_spell_level(([ "inquisitor" : 2, "mage" : 2, "magus" : 2, "paladin" : 2, "psion" : 2 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS wieldskill");
    set_description("This gives the caster proficiency with any kind of weapon, provided they are able to wield it.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    tell_object(caster, "%^YELLOW%^They lyrics to an ancient prayer flood" +
                " into your mind as you begin to hum");
    tell_room(place, "%^YELLOW%^" + caster->QCN + " begins to hum.", caster);
    return "display";
}

int preSpell()
{
    if (caster->query_property("wieldskill")) {
        tell_object(caster, "You already have this spell active.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    tell_room(place, "%^YELLOW%^" + caster->QCN + " chants the lyrics of a " +
              "melodic prayer. Suddenly, " + caster->QP + " eyes brighten with" +
              " enlightenment.", caster);
    tell_object(caster, "%^YELLOW%^You feel a greater understanding of" +
                " combat filling your mind.");

    caster->set_property("wieldskill", 1);
    if (member_array("martial weapon proficiency", (string*)caster->query_temporary_feats()) == -1) {
        caster->add_temporary_feat("martial weapon proficiency");
        trackera = 1;
    }
    if (member_array("exotic weapon proficiency", (string*)caster->query_temporary_feats()) == -1) {
        caster->add_temporary_feat("exotic weapon proficiency");
        trackerb = 1;
    }
    caster->set_property("spelled", ({ TO }));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 8;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
}

void dest_effect()
{
    if (objectp(caster)) {
        caster->remove_property("wieldskill");
        tell_object(caster, "%^YELLOW%^The knowledge of weapon skill leaves you.");
        tell_room(environment(caster), "%^YELLOW%^Frowning for a moment," +
                  " " + caster->QCN + " scratches " + caster->QP + " head.", caster);
        if (trackerb == 1) {
            caster->remove_temporary_feat("exotic weapon proficiency");
        }
        if (trackera == 1) {
            caster->remove_temporary_feat("martial weapon proficiency");
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
