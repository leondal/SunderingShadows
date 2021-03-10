//_storm_cone.c

#include <std.h>

inherit SPELL;

object storm;

void create() {
    ::create();
    set_spell_name("storm cone");
    set_spell_level(5);
    set_spell_type("priest");
    set_spell_sphere("weather");
    set_diety("talos");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^As "+caster->query_cap_name()+" chants low, winds begin to pick up and buffet the area.";
}

void spell_effect(int prof) {

    object ob;

    if ((ob = present("stormcone", place))) {
        tell_room(place,"%^BOLD%^%^CYAN%^The wind storm seems to be growing stronger");
        return;
    }

    tell_room(place,"%^BOLD%^%^CYAN%^Winds whip around you, the air shreaks in a high pitched voice.");

    tell_room(place,"%^BOLD%^%^CYAN%^This room is consumed with a horrid wind storm.");

    ob = new("/d/magic/obj/stormcone");
    ob->set_caster(caster);
    ob->set_level(clevel);
    ob->set_property("spelled",({TO}));
    ob->set_property("spell",TO);
    ob->move(place);
    storm = ob;
    call_out("dest_effect",clevel*14);
}

void dest_effect() {
    ::dest_effect();
    if (objectp(storm)) {
        tell_room(environment(storm),"%^BOLD%^%^CYAN%^The storm slows and fizzles.");
        storm->remove();
    }
    TO->remove();

}

int help() {
    write(
@HELP
Spell  : Storm Cone
Level  : 5th Level
Sphere : Weather
Deity  : Talos
Syntax : chant storm cone

This spell will summon up a violent storm around
the caster to buffet and attack everything in the room
with the caster.
HELP
);
    return 1;
}
