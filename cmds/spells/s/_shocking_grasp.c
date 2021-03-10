// lowlevel evocation school specialty spell. Nienne, 08/09.
//removed mention of non-specialized mages ~Circe~ 8/2/19
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("shocking grasp");
    set_spell_level(([ "mage" : 1, "magus" : 1 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS shocking grasp on TARGET");
    set_description("This spell allows the mage to generate a small electrical charge in their fingertips. They may then "
                    "attempt to touch a foe, discharging it into them in a powerful shock. A caster will find it far easier to contact a foe "
                    "who is carrying or wearing metal items, which will conduct the charge. While this spell can, at first, be considerably "
                    "more painful than other spells of its sphere, a mage can only withhold so much charge in his fingertips, so it will not "
                    "take a great deal of study before the spell reaches its highest potential.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities(({ "lightning" }));
    // school specific mage spell
}

string query_cast_string()
{
    return "%^YELLOW%^Sparks scatter from " + caster->QCN + "'s fingertips as " +
           caster->QS + " spreads " + caster->QP + " hands.%^RESET%^";
}

spell_effect(int prof)
{
    int bonus, i, tracker, roll;
    object* armour;
    string target_limb;

    if (!present(target, environment(caster))) {
        tell_object(caster, "%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }

//  best I could figure to discern if metal armor or weapons are carried by the target, which gives +3 to hit.
    target_limb = target->return_target_limb();

    armour = target->query_armour("torso");
    for (i = 0; i < sizeof(armour); i++) {
        if ((string)armour[i]->query_type() == "chain" || (string)armour[i]->query_type() == "armor" || (string)armour[i]->query_type() == "armour" || (string)armour[i]->query_type() == "plate") {
            tracker = 1;
        }
    }
    armour = target->query_armour("left hand");
    for (i = 0; i < sizeof(armour); i++) {
        if ((string)armour[i]->query_type() == "shield") {
            tracker = 1;
        }
    }
    armour = target->query_armour("right hand");
    for (i = 0; i < sizeof(armour); i++) {
        if ((string)armour[i]->query_type() == "shield") {
            tracker = 1;
        }
    }
    if (sizeof(target->query_wielded())) {
        tracker = 1;
    }
    if (tracker) {
        bonus = 3;
    }

    roll = BONUS_D->process_hit(caster, target, 1, bonus, 0, 1);

    if (!roll || roll == -1 && !caster->query_property("spectral_hand")) {
        tell_object(caster, "%^ORANGE%^You reach out to touch " + target->QCN + ", but " + target->QS + " evades you!%^RESET%^");
        tell_object(target, "%^ORANGE%^" + caster->QCN + " reaches towards you with crackling fingertips, but you dance "
                    "aside!%^RESET%^");
        tell_room(place, "%^ORANGE%^" + caster->QCN + " reaches towards " + target->QCN + " with crackling fingertips, but "
                  + target->QS + " dances aside!%^RESET%^", ({ caster, target }));
        TO->remove();
        return;
    }
    spell_successful();
    tell_object(caster, "%^YELLOW%^You reach out to touch " + target->QCN + ", and the electricity in your fingertips surges forth to shock " + target->QO + "!%^RESET%^");
    tell_object(target, "%^YELLOW%^" + caster->QCN + " reaches out to touch you, and electricity surges from " + target->QP +
                " fingertips to shock you!%^RESET%^");
    tell_room(place, "%^YELLOW%^" + caster->QCN + " reaches out to touch " + target->QCN + ", and the electricity in " + caster->QP +
              " fingertips surges forth to shock " + target->QO + "!%^RESET%^", ({ caster, target }));

    damage_targ(target, target_limb, sdamage, "electricity");
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
