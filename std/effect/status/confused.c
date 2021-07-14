#include <std.h>
#include <magic.h>
#include <skills.h>

#pragma strict_types

#define CONFUSION "/std/magic/confusion"

/**
 * Confusion is always spelled and requires a caster!
 */

inherit STATUS;

int counter;

object caster;

void create()
{
    ::create();
    set_name("effect_confused");
}

void status_effect()
{
    int i;
    if (target && target->query_property("effect_confused")) {
        TO->remove();
        return;
    }

    if (target->query_property("mind_immunity")) {
        int roll = roll_dice(1, 20);
        if (roll < target->query_property("mind_immunity") && roll != 20) {
            tell_object(target,"%^ORANGE%^You endure the confusion, at a price.");
            target->cause_typed_damage(target,target->return_target_limb(),roll_dice(target->query_level(), 8),"mental");
            TO->remove();
            return;
        }
    }

    target->set_property("effect_confused", 1);
    if (objectp(query_param())) {
        caster = query_param();
    }

    counter = duration;
    maintain_confusion(target);
}

void maintain_confusion(object ob)
{
    if (!objectp(caster) ||
        !objectp(ob)) {
        dest_effect(ob);
    }

    if (counter < 0) {
        dest_effect(ob);
    }

    CONFUSION->confuse(caster, ob);
    call_out("maintain_confusion", ROUND_LENGTH, ob);
    counter--;
}

void dest_effect(object ob)
{
    int i;
    if (objectp(ob)) {
        tell_object(ob, "%^ORANGE%^You are no longer confused.%^RESET%^");
        ob->remove_property("effect_confused");
    }
    ::dest_effect();
}
