// Holy Presence

#include <std.h>

inherit SPELL;

object symbol;

void dest_effect();

string query_cast_string() {
    return "%^BOLD%^"+caster->query_cap_name()+" holds up "+caster->query_possessive()+" holy symbol and calls for Selune's favor.";
}

void create() {
    ::create();
    set_spell_name("holy presence");
    set_spell_level(7);
    set_spell_type("priest");
    set_spell_sphere("guardian");
    set_diety("selune");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell() {
    if (present("symbol", place) && present("image", place)) {
        tell_object(caster, "%^BOLD%^You can only have one mystic symbol at a time.%^RESET%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int calign;

    calign = caster->query_alignment();
    switch (calign) {
    case 1:
        symbol = new("/d/magic/obj/lgsymbol");
        break;
    case 2:
        symbol = new("/d/magic/obj/lnsymbol");
        break;
    case 4:
        symbol = new("/d/magic/obj/ngsymbol");
        break;
    case 5:
        symbol = new("/d/magic/obj/tnsymbol");
        break;
    case 7:
        symbol = new("/d/magic/obj/cgsymbol");
        break;
    case 8:
        symbol = new("/d/magic/obj/cnsymbol");
        break;
    }
    if (!objectp(environment(caster))) {
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^MAGENTA%^A great %^WHITE%^glowing%^MAGENTA%^ symbol appears before you!");
    tell_room(environment(caster),"%^BOLD%^%^MAGENTA%^A great %^WHITE%^glowing%^MAGENTA%^ symbol appears before "+caster->query_cap_name()+"!",caster);
    symbol->set_property("spelled",({TO}));
    symbol->set_property("spell",TO);
    symbol->set_caster(caster);
    symbol->move(environment(caster));
    call_out("dest_effect",56);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(symbol) && objectp(environment(symbol))) {
        tell_room(environment(symbol),"%^MAGENTA%^The %^WHITE%^%^BOLD%^glowing%^RESET%^%^MAGENTA%^ symbol shimmers and fades.");
        symbol->remove();
    }
    TO->remove();;
}

int help(string str) {
    write(
@HELP
Spell  : Holy Presence
Level  : 7th Level
Sphere : Guardian
Deity  : Selune
Syntax : chant holy presence

This spell will cause a glowing, radiant image of
the caster's holy symbol to appear in the room.
Various effects can happen while the symbol is
present.

HELP
);
    return 1;
}
