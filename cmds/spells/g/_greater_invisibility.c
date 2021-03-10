// New illusion spell based on chameleon. Nienne, 11/09.
//removed mention of non-specialized mages ~Circe~ 8/2/19
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;
object invisob;

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("greater invisibility");
    set_spell_level(([ "mage" : 4, "bard" : 4, "assassin" : 4, "inquisitor" : 4, "magus" : 4 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS greater invisibility");
    set_description("This spell, available only to masters of illusion, allows the caster to enhance the normally fragile "
                    "distortion an invisibility spell offers. The more powerful version of this spell will not fail even if the caster "
                    "becomes involved in combat. However, due to the additional concentration required to maintain this stronger variant, the "
                    "spell has a chance to drain from the caster every time he or she moves.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
                        "mage" : ([ "jade circlet" : 1, ]),
                        ]));
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^MAGENTA%^" + caster->QCN + " suddenly seems to become distinctly uninteresting.";
}

void spell_effect(int prof)
{
    caster = CASTER;
    place = PLACE;
    tell_object(caster, "%^MAGENTA%^You let out a gentle %^CYAN%^t%^GREEN%^r%^CYAN%^i%^GREEN%^l%^CYAN%^l%^MAGENTA%^, and "
                "as the sound escapes your lips you feel yourself %^RESET%^fading %^MAGENTA%^away!%^RESET%^");
    tell_room(place, "%^MAGENTA%^" + caster->QCN + " lets out a gentle %^CYAN%^t%^GREEN%^r%^CYAN%^i%^GREEN%^l%^CYAN%^l%^MAGENTA%^. "
              "Even as the sound escapes " + caster->QP + " lips " + caster->QS + " starts %^RESET%^fading %^MAGENTA%^away!%^RESET%^", caster);
    addSpellToCaster();
    call_out("targ_vanish", 2);
}

void targ_vanish()
{
    int num;
    num = (clevel / 2);
    spell_successful();
    invisob = new("/d/magic/obj/invisobgreater.c");
    invisob->set_property("spell", TO);
    invisob->set_property("spelled", ({ TO }));
    invisob->set_player_name(caster->query_name());
    invisob->set_mychance(num);
    invisob->move(caster);
    return;
}

void dest_effect()
{
    if ((string)TO->query_spell_type() == "mage") {
        tell_object(caster, "%^MAGENTA%^The circlet disappears from your brow, as the illusion it held is dropped.%^RESET%^");
    } else {
        tell_object(caster, "%^MAGENTA%^An echoing quiver of sound reaches your ears, counteracting the spell's resonance, and you reappear.%^RESET%^");
    }
    tell_room(environment(caster), "%^MAGENTA%^With a slight shimmer, " + caster->QCN + " appears before you.%^RESET%^", caster);
    if (objectp(invisob)) {
        invisob->show_me();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
