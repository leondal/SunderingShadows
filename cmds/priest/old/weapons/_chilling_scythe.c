// Chilling Scythe

#include <std.h>

inherit SPELL;

object sword;

create() {
    ::create();
    set_spell_name("chilling scythe");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("necromantic");
    set_diety("kelemvor");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^YELLOW%^"+caster->query_cap_name()+" spreads "+caster->query_possessive()+" arms wide and calls for Kelemvor's aid!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^A scythe appears in your hand.");
        tell_room(place,"A scythe appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    sword = new("/d/magic/obj/cscythe");
    sword->move(caster);
caster->force_me("wield scythe");
    spell_successful();
    call_out("dest_effect",clevel*8);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(sword) && objectp(caster) && objectp(environment(sword))) {
        tell_object(caster,"%^BOLD%^The scythe disappears!");
        tell_object(environment(sword),"%^BOLD%^The scythe disappears from your hand!");
        tell_room(environment(environment(sword)),"%^BOLD%^The scythe disappears from "+environment(sword)->query_cap_name()+"'s hand.",({caster,environment(sword)}));
        sword->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Chilling Scythe
Level  : 2nd level
Sphere : Necromantic
Deity  : Kelemvor
Syntax : chant chilling scythe

This spell will create a scythe that causes great
chilling damage that appears in the caster's hand.
HELP
);
    return 1;
}
