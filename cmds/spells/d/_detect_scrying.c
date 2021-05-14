// Detect Scrying
// Informs players if they are being viewed
// by a scrying device
// Thorn@ShadowGate
// 5 January 2001
#include <spell.h>
#include <magic.h>
#include <daemons.h>
#define SCRY_D "/daemon/ic_scry_locate_d"
inherit SPELL;

object detector;

void create()
{
    ::create();
    set_spell_name("detect scrying");
    set_spell_level(([ "mage" : 4, "bard" : 4, "inquisitor" : 4, "cleric" : 4 ]));
    set_domains("knowledge");
    set_spell_sphere("divination");
    set_syntax("cast CLASS detect scrying");
    set_description("By means of this spell, the wizard immediately becomes aware of any attempt to observe him by means of clairvoyance, clairaudience, or magic mirror.  This also reveals the use of crystal balls or other magical scrying devices, provided the attempt is within the area of effect of the spell.  Since the spell is centered on the spellcaster, it moves with him, enabling him to 'sweep' areas for the duration of the spell.\n\nWhen a scrying attempt is detected, the scryer must immediately roll a saving throw.  If this is failed, the appearance and general location of the scryer immediately become known to the wizard who cast this spell. The general location is the room and area where the scryer is located at the time.\n\nThis spell does not protect from scrying, however.  Despite the fact that you have detected the scrying, you cannot end the scrying without casting a spell or using an object that protects from scrying.");
    set_verbal_comp();
    set_somatic_comp();
    set_peace_needed(1);
    set_components(([
                        "mage" : ([ "piece of mirror" : 1, "tiny hearing trumpet" : 1, ]),
                    ]));
    set_helpful_spell(1);
}

string query_cast_string()
{
    if (spell_type == "bard") {
        return "%^BOLD%^%^GREEN%^" + caster->QCN + " recites a short rhyme.%^RESET%^";
    }
    return "%^BOLD%^CYAN%^" + caster->QCN + " places " +
           "a tiny hearing trumpet up against a small piece of glass "
           "and places " + caster->QP + " ear to the trumpet!";
}

void spell_effect(int prof)
{
    int num, bonus, power;
    int duration;
    object temp;

    ::spell_effect();

    if (temp = caster->query_property("detect scrying")) {
        if (!objectp(temp)) {
            caster->remove_property("detect scrying");
        } else {
            tell_object(caster, "%^BOLD%^RED%^You are already detecting "
                        "scrying attempts!");
            if (objectp(TO)) {
                TO->remove();
            }
            return;
        }
    }
    tell_room(place, "%^BOLD%^GREEN%^For a brief moment, the air around " +
              "" + caster->QCN + " shimmers with a magical aura!");

    caster->set_property("spelled", ({ TO }));
    bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
    power = clevel + bonus + random(6);

    detector = SCRY_D->add_detect_scrying(caster);
    if (!objectp(detector)) {
        tell_object(caster, "%^BOLD%^RED%^Something is wrong that "
                    "a wiz might want to look at!");
        dest_effect();
        return;
    }
    detector->set_detect_power(power);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 6;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
    return;
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, "%^CYAN%^%^BOLD%^The magic detecting scrying fades from around you.%^RESET%^");
        caster->remove_property_value("spelled", ({ TO }));
    }
    if (objectp(detector)) {
        detector->self_destruct();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
