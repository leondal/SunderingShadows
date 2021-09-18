// Detect Invisibility
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

object oldenv, * conceal;
int i, num = 0;
    int bonus;

void create()
{
    ::create();
    set_spell_name("night auspex");
    set_spell_level(([ "innate" : 5 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS night auspex");
    set_description("You expend a little of your bloodlust to gain true sight.");
    set_blood_magic(1);
    set_helpful_spell(1);
    set_silent_casting(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^" + caster->QCN + " closes " +
        caster->QP + " eyes and focuses intently!%^RESET%^";
}

int preSpell()
{
    if (caster->detecting_invis() || caster->true_seeing()) {
        tell_object(caster, "You are already detecting invisible.");
        return 0;
    }
    return 1;
}

void spell_effect()
{
    spell_successful();
    caster->add_bloodlust(-500);

    if (member_array(caster->query_race(), PLAYER_D->night_races()) != -1) {
        bonus = -10;
    }else {
        bonus = 8;
    }

    tell_room(environment(caster), "%^BOLD%^%^BLACK%^%^" + caster->QCN + "'s eyes snap open and flash crimson for a instant before returning to their normal shade of " + caster->query_eye_color() + ".", caster);

    tell_object(caster, "%^BOLD%^%^BLACK%^Your eyes snap open and flash deep black for an instant before returning to their normal shade of " + caster->query_eye_color() + "!%^RESET%^");

    caster->set_true_seeing(1);
    target->add_sight_bonus(bonus);
    target->set_property("darkvision",1);
    caster->set_property("spelled", ({ TO }));
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;

    set_end_time();
    call_out("dest_effect", spell_duration);
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, "%^BOLD%^%^BLACK%^Your vision is suddenly hazy as your eyes return to normal.%^RESET%^");
        tell_room(environment(caster), "%^BOLD%^%^BLACK%^" + caster->QCN + "'s eyes glaze over for a brief instant before returning to normal.%^RESET%^", caster);
        target->remove_property("darkvision",1);
        target->add_sight_bonus(-bonus);
        caster->set_true_seeing(0);
        caster->remove_property_value("spelled", ({ TO }));
        remove_call_out("flip");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
