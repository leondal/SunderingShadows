#include <spell.h>
#include <magic.h>
inherit SPELL;

int power;

void create()
{
    ::create();
    set_spell_name("statue");
    set_spell_level(([ "oracle" : 7, "mage":7]));
    set_spell_sphere("alteration");
    set_mystery( ({ "stone", "metal" }) );
    set_syntax("cast CLASS statue on TARGET");
    set_description("You attempt to turn your target into stone. For the duration of the spell they will be a stone statue, able to hear and understand everything, but being unable to act. They'll have resilience that of a stone statue and will retain their hp.");
    set_verbal_comp();
    set_save("will");
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^WHITE%^%^BOLD%^" + caster->QCN + " holds up a piece of marble in the air.";
}

spell_effect()
{
    int dam = sdamage;
    int duration = (clevel / 10 + roll_dice(1, 2));
    spell_successful();
    if (do_save(target, 0)) {
        tell_object(caster, "%^BOLD%^%^WHITE%^" + target->QCN + " shakes off your attempt to turn them into stone!");
        tell_object(target, "%^BOLD%^%^WHITE%^You overpower " + caster->QCN + "'s attempt to turn you into stone!");
        tell_room(place, "%^BOLD%^%^WHITE%^" + target->QCN + "'s face momentarily turns white marble, but then  " + target->QS + " shake off the spell.", ({ caster, target }));
        dest_effect();
        return;
    }
    tell_object(target, "%^BOLD%^%^WHITE%^With horror you realize your body is not a piece of marble.");
    tell_room(place, "%^BOLD%^%^%^WHITE%^" + target->QCN + " turns into a marble statue!", target);
    target->set_paralyzed(duration * 8, "%^WHITE%^%^BOLD%^You are a piece of marble and cannot do a thing!");
    power = clevel * 3 / 2;
    target->set_property("damage resistance", -power);
    target->set_property("spell damage resistance", -power * 5);
    call_out("checker", ROUND_LENGTH);
}

void checker()
{
    if (!objectp(target)) {
        dest_effect();
    }
    if (!target->query_paralyzed()) {
        // freedom of movement case
        dest_effect();
    }
    call_out("checker", ROUND_LENGTH);
}

void dest_effect()
{
    if (find_call_out("checker") != -1) {
        remove_call_out("checker");
    }
    if (objectp(target)) {
        tell_object(target, "%^BOLD%^%^WHITE%^You inhale deeply as your body turns back into flesh!");
        target->set_paralyzed(0);
        target->set_property("damage resistance", -power);
        target->set_property("spell damage resistance", -power * 5);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
