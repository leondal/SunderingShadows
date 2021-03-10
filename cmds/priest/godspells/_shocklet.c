//_shocklet.c
// mon file moved to /d/magic/mon/ Ares/Styx 1/29/05

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, v;
object caster, place, endplace, device;
object elem;

void create() {
    ::create();
    set_spell_name("shocklet");
    set_spell_level(6);
    set_spell_type("priest");
    set_diety("talos");
    set_spell_sphere("elemental air");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^YELLOW%^"+caster->query_cap_name()+" looks up at the sky and calls to Talos!";
}

int preSpell() {
    if (present("celemdevicex999",caster)) {
        tell_object(caster,"You can only control one elemental at a time!\n");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    string him;
    mapping tmp;

    caster = CASTER;
    place = PLACE;
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    him = caster->query_cap_name();
    tell_room(place,"%^ORANGE%^"+him+" raises "+caster->query_possessive()+" hands in what looks like agony."
              +" Mists swirl rapidly above "+caster->query_possessive()+" head. "
              +" You almost see a small hole in the fabric of the world in the middle.", caster);
    tell_object(caster,"%^ORANGE%^Your hands are lifted above you by a tremendous force."
                +" Dark mists swirl above your head. You see a small opening in the middle of those mists.");
    call_out("next_step",10);
}

void next_step() {
    string him;

    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    him = caster->query_cap_name();
    tell_room(place,"%^BOLD%^You see raw power extend from "+him+"'s hands "
              +"the power seems to catch onto something and struggle to pull it "
              +"through that small hole.",caster);
    tell_object(caster,"%^BOLD%^Raw power thrusts from your hands as you attempt "
                +"to leash a lightning elemental from its home plane.");
    call_out("step3",5);
}

void step3() {
    string him;
    object ob;

    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    him = caster->query_cap_name();
    ob = new("/d/magic/mon/lelemental");
    elem = ob;
    ob->set_property("spell",TO);
    ob->set_property("spelled", ({TO}) );
    ob->set_property("spell_creature", TO);
    device = new("/d/magic/obj/celemholder");
    tell_room(place,"%^BOLD%^The struggle seems to last an eternity, "
              +"but it ends with "+him+" over powering the prey and .....",caster);
    tell_object(caster,"%^BOLD%^You struggle with the being on the other end."
                +"Gradually you pull it closer to you. then suddenly......\n");
    tell_room(place,"%^BOLD%^%^YELLOW%^Before you stands a lightning elemental!");
    tell_object(caster,"%^BOLD%^%^YELLOW%^Unable to resist your power the "
                +" being bows in acquiescence and awaits your command.\n");
    tell_room(place,"%^BOLD%^%^YELLOW%^Unable to resist "+him+"'s power, the lightning elemental "
              +" bows down to "+caster->query_objective()+"!",caster);
    device->set_elemental(ob);
    device->set_caster(caster);
    caster->add_follower(ob);
    device->move(caster);
    device->set_property("spell",TO);
    device->set_property("spelled", ({TO}) );
    ob->move(place);
}

void dest_effect() {
    ::dest_effect();
    if(objectp(elem)){
        tell_room(environment(elem), "%^YELLOW%^The elemental disperses into the air.");
        elem->move("/d/shadowgate/void");
        elem->remove();
    }

    if(objectp(device))
        device->remove();
    TO->remove();
}

int help() {
    write(
@OLI
Spell  : Shocklet
Level  : 6th Level
Sphere : Elemental Air
Deity  : Talos
Syntax : chant shocklet

This spell will summon a lightning elemental for
you to command. Such creatures are native to
different planes, and existence in this plane
is extremely painful for them.
"command elemental to <action>" will command the summoned elemental.

OLI
);
    return 1;
}
