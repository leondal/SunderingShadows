// needs to match "alter self" item except for messages, needs to use same profile template
#include <std.h>
#include <objects.h>
#include <daemons.h>
inherit "/std/races/shapeshifted_races/spell_alter_self";

int change_into_message(object obj) {
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^GREEN%^You turn your mind inwards as the spell begins to take effect.");
    tell_object(obj,"%^RESET%^%^BOLD%^A ripple of energy dances across your skin, revealing features not your own.");
    tell_object(obj,"%^RESET%^%^RED%^The energy wavers again and then sets into the uniform appearance of another being!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^A ripple of energy dances across "+obj->QCN+"'s skin, revealing different features.",obj);
    tell_room(environment(obj),"%^YELLOW%^The energy wavers again and then sets, granting "+obj->QCN+" the uniform appearance of another being!",obj);
    return 1;
}

int change_outof_message(object obj) {
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You attune your mind to the person you used to be.");
    tell_object(obj,"%^RESET%^%^BLUE%^You feel the existing glamer waver unsteadily.");
    tell_object(obj,"%^RESET%^%^GREEN%^The invocation flickers and snuffs out, returning you to your normal appearance.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s body grows still "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s features waver, an illusion no longer holding steady.",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^The glamer ripples once more and suddenly "+obj->QCN+" looks distinctly different!",obj);
    return 1;
}

int can_cast()
{
    return 1;
}
