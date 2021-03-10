// Ice Blade

#include <std.h>

inherit SPELL;

object sword;

create() {
    ::create();
    set_spell_name("ice blade");
    set_spell_level(4);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_diety("auril");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BOLD%^"+caster->query_cap_name()+" spreads "+caster->query_possessive()+" arms wide and begins calling for Auril's aid!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^CYAN%^A sword made of ice appears in your hand.");
    }
    tell_room(place,"%^CYAN%^A sword of ice appears in "+caster->query_cap_name()+"'s hand.",caster);
    sword = new("/d/magic/obj/iceblade");
    sword->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield ice blade");
    spell_successful();
    call_out("dest_effect",clevel*16);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(sword) && objectp(caster)) {
        //caster->force_me("unwield ice blade");
        tell_object(caster,"%^BOLD%^The blade of ice disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^The ice blade disappears from "+caster->query_cap_name()+"'s hand.",caster);
        sword->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Ice Blade
Level  : 4th Level
Sphere : Combat
Deity  : Auril
Syntax : chant ice blade

This spell will create a sword-shaped formation of jagged,
swirling ice shards that will appear in the caster's hand.
HELP
);
    return 1;
}
