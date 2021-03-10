//_dark_suns_rays.c Updated by Circe.  Moved to Cyric
//when Bane was added to the game.  4/14/04
//__reaving_blades.c

#include <std.h>

inherit SPELL;

object blades;

void create() {
    ::create();
    set_spell_name("dark suns rays");
    set_spell_type("priest");
    set_spell_sphere("evocation");
    set_spell_level(4);
    set_verbal_comp();
    set_somatic_comp();
    set_diety("cyric");
}

string query_cast_string() {
    return "%^BLUE%^"+caster->query_cap_name()+" cackles demonically, as "+caster->query_subjective()+" summons the power of the Dark Sun!";
}

int preSpell() {
    if (!sizeof(caster->query_attackers())) {
        tell_object(caster,"You must be in the midst of showing the power of your god to use this power, kill them all, and I will help.");
        return 0;
    }

    if (present(caster->query_name()+"blades",place)) {
        tell_room(place,"%^BOLD%^%^BLUE%^You hear Cyric snarl with disdain at "+caster->query_cap_name()+"'s presumption to demand more help.",caster);
        tell_object(caster,"%^BOLD%^%^BLUE%^You hear Cyric snarl with disdain at you for your presumption to demand more help.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {


    tell_room(place,"%^BLUE%^Two black rays of darkness emerge before you, spinning wildly as they seek out flesh to slice!");

    blades = new("/d/magic/obj/reaving_blades");
    blades->set_damage(2,clevel);
    blades->set_hd(clevel,100);
    blades->set_attackers(caster->query_attackers());
    blades->add_id(caster->query_name()+"blades");
    blades->move(place);
    place->add_combatant(blades);
    blades->set_property("spelled",({TO}));
    blades->set_property("spell",TO);
    blades->set_property("spell_creature", TO);
    caster->add_follower(blades);
    call_out("dest_effect",10);

}

void dest_effect() {
    ::dest_effect();
    if (objectp(blades)) {
        tell_room(environment(blades),"%^BLUE%^The rays cease spinning and slowly fade out of existence, leaving nothing behind.");
        blades->remove();

    }
    TO->remove();
}


int help() {
    write(
@OLI
Spell  : Dark Sun's Rays
Level  : 4th Level
Sphere : Evocation
Deity  : Cyric
Syntax : chant dark suns rays

This spell can be cast only in battle to help the caster gain victory over the present enemies. Cyric will send a pair of powerful blades of darkness down to finish off the opponents of his greater glory and power to be.

OLI
);
    return 1;
}
