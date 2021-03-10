// Water Whip

#include <std.h>

inherit SPELL;

object whip;

create() {
    ::create();
    set_spell_name("water whip");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("elemental water");
    set_diety("istishia");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BLUE%^"+caster->query_cap_name()+" raises "+caster->query_possessive()+" arms to the sky and calls for Istishia's aid!";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^A whip formed from water appears in your hand.");
        tell_room(place,"%^BLUE%^A whip made of water appears in "+caster->query_cap_name()+"'s hand.",caster);
    }
    whip = new("/d/magic/obj/waterwhip");
    whip->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield water whip");
    spell_successful();
    call_out("dest_effect",(5+clevel/2)*8);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(whip) && objectp(caster)) {
        //caster->force_me("unwield water whip");
        tell_object(caster,"%^BOLD%^The water whip disappears from your hand!");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^The whip disappears from "+caster->query_cap_name()+"'s hand.",caster);
        whip->remove();
    }
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Water Whip
Level  : 2nd Level
Sphere : Elemental Water
Deity  : Istishia
Syntax : chant water whip

This spell will create a whip-shaped formation of pure
water that will appear in the caster's hand.
HELP
);
    return 1;
}
