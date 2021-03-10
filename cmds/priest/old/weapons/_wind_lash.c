// Whip of Flame

#include <std.h>

inherit SPELL;

object whip;

create() {
    ::create();
    set_spell_name("wind lash");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("weather");
    set_diety("talos");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BOLD%^"+caster->query_cap_name()+" raises "+caster->query_possessive()+" arms to the sky and calls to Talos!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^A whip formed from air appears in your hand.");
        tell_room(place,"A whip made of air appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    whip = new("/d/magic/obj/windlash");
    whip->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield wind lash");
    spell_successful();
    call_out("dest_effect",clevel*12);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(whip) && objectp(caster)) {
        //caster->force_me("unwield wind lash");
        tell_object(caster,"%^BOLD%^The wind lash disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^The lash disappears from "+caster->query_cap_name()+"'s hand.",caster);
        whip->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Wind Lash
Level  : 2nd Level
Sphere : Combat
Deity  : Talos
Syntax : chant wind lash

This spell will create a whip-shaped formation of pure
air that will appear in the caster's hand.
HELP
);
    return 1;
}
