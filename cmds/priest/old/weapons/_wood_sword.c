// Ice Blade

#include <std.h>

inherit SPELL;

object sword;

create() {
    ::create();
    set_spell_name("wood sword");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_diety("mielikki");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return caster->query_cap_name()+" spreads "+caster->query_possessive()+" arms wide and calls for Mielikki's aid!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^A sword made of wood appears in your hand.");
        tell_room(place,"A sword of wood appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    sword = new("/d/magic/obj/woodsword");
    sword->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield wood sword");
    spell_successful();
    call_out("dest_effect",clevel*16);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(sword) && objectp(caster)) {
        caster->force_me("unwield wood sword");
        tell_object(caster,"%^BOLD%^The wood sword disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^The wood sword disappears from "+caster->query_cap_name()+"'s hand.",caster);
        sword->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Wood Sword
Level  : 2nd Level
Sphere : Combat
Deity  : Mielikki
Syntax : chant wood sword

This spell will create a powerful wooden sword
that will appear in the caster's hand.
HELP
);
    return 1;
}
