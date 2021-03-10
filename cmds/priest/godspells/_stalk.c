


#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

object invisob, caster, place;

create() {
    ::create();
    set_spell_name("stalk");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("illusion");
   //set_deity("mielikki");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell() {
    if (place->query_property("indoors")) {
        tell_object(caster,"You need to be outdoors to wrap yourself in the nature you love so much.");
        return 0;
    }
    return 1;
}

spell_effect(int prof) {
    caster = CASTER;
    place = PLACE;
    target = TARGET;
    if (!target)
        target=caster;
    tell_object(caster,"%^GREEN%^Your words and prayers begin to fold nature around you.");
    tell_room(place,"%^GREEN%^"+caster->query_cap_name()+" prays as "+caster->query_subjective()+" pulls nature and shrouds "+caster->query_objective()+"self.",caster);
    call_out("targ_vanish",2);
}

void targ_vanish() {
    spell_successful();
    invisob=new("/d/magic/obj/hide.c");
    invisob->set_property("spell",TO);
    invisob->set_property("spell",({TO}) );
    invisob->set_player_name(caster->query_name());
    invisob->move(target);

    return;
}

void dest_effect() {
    ::dest_effect();
    if (!objectp(invisob)) {
        TO->remove();
        return;
    }
    invisob->show_me();
    TO->remove();
}

string query_cast_string() {
    return "%^GREEN%^"+caster->query_cap_name()+" begins to pull the nature of the world around "+caster->query_objective();
}

int help() {
    write(
@HELP
Spell  : Stalk
Level  : 2nd Level
Sphere : Illusion
Deity  : Mielikki
Syntax : chant stalk

Stalk gives the target the ability to move unnoticed through the
outdoors.

HELP
);
    return 1;
}
