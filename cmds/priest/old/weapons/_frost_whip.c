// frost Whip

#include <std.h>

inherit SPELL;

object whip;

create() {
    ::create();
    set_spell_name("frost whip");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("weather");
    set_diety("auril");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^CYAN%^"+caster->query_cap_name()+" raises "+caster->query_possessive()+" arms to the sky and calls for Auril's aid!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^A whip formed from frost appears in your hand.");
        tell_room(place,"%^CYAN%^A whip made of frost appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    whip = new("/d/magic/obj/frostwhip");
    whip->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield frost whip");
    spell_successful();
    call_out("dest_effect",clevel*12);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(whip) && objectp(caster)) {
       // caster->force_me("unwield frost whip");
        tell_object(caster,"%^BOLD%^The frost whip disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^The whip disappears from "+caster->query_cap_name()+"'s hand.",caster);
        whip->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Frost Whip
Level  : 2nd Level
Sphere : Weather
Deity  : Auril
Syntax : chant frost whip

This spell will create a whip-shaped formation of
cold that will appear in the caster's hand.
HELP
);
    return 1;
}
