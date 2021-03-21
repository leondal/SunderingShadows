// moved from "fly" to "levitate" to avoid confusion & lower level casting. N, 4/14.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

string message_out, message_in;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("levitate");
    set_spell_level(([ "mage" : 2, "oracle" : 2, "monk": 3, "magus" : 2, "cleric" : 2 ]));
    set_domains("travel");
    set_monk_way("way of the elements");
    set_mystery("dragon");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS levitate on TARGET");
    set_description("This spell will give the target the ability to levitate. The target will find traveling over long "
                    "distances to be very easy when under the influence of this spell, and will use very little stamina to travel.\n\nPlease "
                    "note: This spell will remove your previously set enter and exit messages.  If you had these set previously, you may "
                    "need to reset them after using the levitate spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

int preSpell()
{
    if (!objectp(target)) {
        tell_object(caster, "This spell requires a target.");
        return 0;
    }
    if (target->query_in_vehicle()) {
        tell_object(caster, "You can't cast this on a mounted target.");
        return 0;
    }
    if ((int)target->query_property("flying")) {
        tell_object(caster, "Your target is already levitating!");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^BLUE%^%^You hair begins to stir around" +
                " in a light breeze.");
    tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + "'s hair begins to " +
              "stir around in a light breeze as " + caster->QS + " draws upon a spell.", caster);
    return "display";
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;
    if (!present(target, place)) {
        tell_object(caster, "Your target has left the area.");
        dest_effect();
        return;
    }
    if (target == caster) {
        tell_room(place, "%^BOLD%^%^CYAN%^Rising up off the ground," +
                  " " + caster->QCN + " floats into the air.", target);
        tell_object(target, "%^BOLD%^%^CYAN%^Rising up off the ground," +
                    " you float into the air.");
    }else {
        tell_room(place, "%^BOLD%^%^BLUE%^" + target->QCN + " begins to float up into the air "
                  "as " + caster->QCN + " gives " + target->QO + " the power to levitate.", ({ caster, target }));
        tell_object(caster, "%^BOLD%^%^BLUE%^As you finish your spell, " + target->QCN + " begins "
                    "to levitate!");
        tell_object(target, "%^BOLD%^%^BLUE%^As " + caster->QCN + " finishes " + caster->QP + " spell, you "
                    "can feel yourself floating up into the air!");
    }
    target->set_property("flying", 1);
    target->set_property("spelled", ({ TO }));
    target->set_property("endurance", (clevel / 8));
    message_in = target->query_message_in();
    message_out = target->query_message_out();
    //commenting out to fix enter/exit message bug Odin 2/21/2020
    //target->set_property("MIN", "$N floats in.");
    //target->set_property("MOUT", "$N drifts to the $D.");
    target->set_property("added short", ({ "%^BOLD%^%^BLUE%^ (levitating)%^RESET%^" }));
    addSpellToCaster();
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if (objectp(target)) {
        tell_object(target, "%^BOLD%^%^BLUE%^The magic fades from you and you rapidly" +
                    " descend back to the ground!");
        tell_room(environment(target), "%^BOLD%^%^BLUE%^As the magic fades from" +
                  " " + target->QCN + ", " + target->QS + " rapidly descends back to the ground!", target);
        target->set_property("flying", -1);
        target->set_property("endurance", (-(clevel / 8)));
        //see above
        //target->remove_property("MIN");
        //target->remove_property("MOUT");
        target->remove_property_value("added short", ({ "%^BOLD%^%^BLUE%^ (levitating)%^RESET%^" }));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
