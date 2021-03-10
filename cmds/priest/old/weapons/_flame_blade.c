// Flame Blade

#include <std.h>

inherit SPELL;

object sword;

create() {
    ::create();
    set_spell_name("flame blade");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("elemental fire");
    set_diety("kossuth");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^RED%^"+caster->query_cap_name()+" spreads "+caster->query_possessive()+" arms wide and begins chanting to Kossuth!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^RED%^A sword made of pure fire appears in your hand.");
        tell_room(place,"A sword of pure %^RED%^fire%^RESET%^ appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    sword = new("/d/magic/obj/flameblade");
    sword->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield flame blade");
    spell_successful();
    call_out("dest_effect",(4+clevel/2)*10);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(sword) && objectp(caster)) {
        //caster->force_me("unwield flame blade");
        tell_object(caster,"%^RED%^The blade of fire disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^%^RED%^The flame blade disappears from "+caster->query_cap_name()+"'s hand.",caster);
        sword->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Flame Blade
Level  : 2nd Level
Sphere : Elemental Fire
Deity  : Kossuth
Syntax : chant flame blade

This spell will create a sword-shaped formation of pure
fire that will appear in the caster's hand.
HELP
);
    return 1;
}
