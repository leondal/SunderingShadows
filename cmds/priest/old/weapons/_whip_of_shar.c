// Whip of Flame

#include <std.h>

inherit SPELL;

object whip;

create() {
    ::create();
    set_spell_name("whip of shar");
    set_spell_level(3);
    set_spell_type("priest");
    set_spell_sphere("necromantic");
    set_diety("shar");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BOLD%^"+caster->query_cap_name()+" raises "+caster->query_possessive()+" arms to the sky and calls on Shar's power!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^A black whip-like beam appears in your hand.");
        tell_room(place,"A black whip appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    whip = new("/d/magic/obj/sharwhip");
    whip->move(caster);
    caster->force_me("wield whip of shar");
    spell_successful();
    call_out("dest_effect",clevel*8);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(whip) && objectp(caster)) {
        //caster->force_me("unwield whip of shar");
        tell_object(caster,"%^BOLD%^The whip disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^The whip disappears from "+caster->query_cap_name()+"'s hand.",caster);
        whip->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Whip of Shar
Level  : 3rd Level
Sphere : Necromantic
Deity  : Shar
Syntax : chant whip of shar

This spell will create a flickering black beam of
force that will appear in the caster's hand and can
be used as a whip.
HELP
);
    return 1;
}
