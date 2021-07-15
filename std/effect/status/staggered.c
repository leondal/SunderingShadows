#include <std.h>
#include <magic.h>
#include <skills.h>

inherit STATUS;

int power;

void create()
{
    ::create();
    set_name("effect_staggered");
}
int status_effect()
{
    int i;

    if (target->query_property("effect_staggered") > 1) {
        TO->remove();
        return;
    }

    target->set_property("effect_staggered", 1);
    if (userp(target)) {
        target->set_static("spell interrupt", "%^BOLD%^%^RED%^You are staggered.");
    } else {
        target->spell_interrupt("spell interrupt", "%^BOLD%^%^RED%^You are staggered.");
    }


    tell_object(target, "%^RED%^You are staggered and can barely move.%^RESET%^");
    tell_room(ENV(target), "%^RED%^" + target->QCN + "'s face turns dull," + target->QS + " appears to be staggered.", target);


    call_out("dest_effect", ROUND_LENGTH * duration, target);
    return 1;
}

int dest_effect(object ob)
{
    int i;
    if (objectp(ob)) {
        ob->set_property("effect_staggered", -1);

        if (ob->query_property("effect_staggered")) {
            tell_object(ob, "%^RED%^You no longer feel staggered.%^RESET%^");
        }

        if (userp(ob)) {
            ob->set_static("spell interrupt", 0);
        } else {
            ob->remove_property("spell interrupt");
        }

        tell_room(ENV(ob), "%^RED%^" + ob->QCN + " no longer looks staggered.", ob);
    }
    ::dest_effect();
    return 1;
}
