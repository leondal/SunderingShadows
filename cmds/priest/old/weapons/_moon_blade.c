// Ice Blade

#include <std.h>

inherit SPELL;

object sword;

create() {
    ::create();
    set_spell_name("moon blade");
    set_spell_level(3);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_diety("selune");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^YELLOW%^"+caster->query_cap_name()+" spreads "+caster->query_possessive()+" arms wide and calls for Selune's aid!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^A sword made of moonlight appears in your hand.");
        tell_room(place,"A sword of moonlight appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    sword = new("/d/magic/obj/moonblade");
    sword->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield moonblade");
    spell_successful();
    call_out("dest_effect",clevel*16);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(sword) && objectp(caster)) {
        //caster->force_me("unwield moonblade");
        tell_object(caster,"%^BOLD%^The blade of moonlight disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^The moon blade disappears from "+caster->query_cap_name()+"'s hand.",caster);
        sword->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Moon Blade
Level  : 3rd Level
Sphere : Combat
Deity  : Selune
Syntax : chant moon blade

This spell will create a sword-shaped formation of pure
moonlight that will appear in the caster's hand.
HELP
);
    return 1;
}
