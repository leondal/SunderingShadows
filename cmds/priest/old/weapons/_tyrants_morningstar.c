//Tyrant's Morningstar - changed with the addition of Bane
//Circe 4/14/04
// Mace of Xvim - old

#include <std.h>

inherit SPELL;

object morningstar;

create() {
    ::create();
    set_spell_name("tyrants morningstar");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_diety("bane");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BOLD%^%^BLACK%^"+caster->query_cap_name()+" raises "+caster->query_possessive()+" arms to the sky and calls for Bane's aid!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^GREEN%^A powerful morningstar appears in your hand.");
        tell_room(place,"A morningstar appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    morningstar = new("/d/magic/obj/banestar");
    morningstar->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield tyrants morningstar");
    spell_successful();
    call_out("dest_effect",clevel*16);
//changed dest_effect time to be level dependent 
//like other weapon spells.  Circe
}

void dest_effect() {
    ::dest_effect();
    if (objectp(morningstar) && objectp(caster)) {
        //caster->force_me("unwield tyrants morningstar");
        tell_object(caster,"%^GREEN%^The morningstar disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^%^GREEN%^The morningstar disappears from "+caster->query_cap_name()+"'s hand.",caster);
        morningstar->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Tyrants Morningstar
Level  : 2nd Level
Sphere : Combat
Deity  : Bane
Syntax : chant tyrants morningstar

This spell will create a morningstar that will appear
in the caster's hand.
HELP
);
    return 1;
}
