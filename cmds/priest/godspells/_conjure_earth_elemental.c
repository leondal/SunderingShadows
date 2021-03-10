//_conjure_earth_elemental.c
// mon file moved to /d/magic/mon/ Ares/Styx 1/29/05

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, v;
object caster, place, endplace;
object elem;

void clean_up() {
    return 1;
}

void create() {
    ::create();
    set_spell_name("conjure earth elemental");
    set_spell_level(7);
    set_spell_type("priest");
    set_diety("grumbar");
    set_spell_sphere("elemental");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BOLD%^%^GREEN%^"+caster->query_cap_name()+" looks up at the sky and begins chanting to Grumbar!";
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

    tell_room(place,"%^BOLD%^%^GREEN%^"+him+" raises "+caster->query_possessive()+" hands in what looks like agony."
              +" Mists swirl rapidly above "+caster->query_possessive()+" head. "
              +" You almost see a small hole in the fabric of the world in the middle.", caster);
    tell_object(caster,"%^BOLD%^%^GREEN%^You hands are lifted above you by a tremendous force."
                +" Dark mists swirl above your head. You see a small opening in the middle of those mists.");
    call_out("next_step",5);
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
                +"to leash an earth elemental from its home plane.\n");
    call_out("step3",5);
}

void step3() {
    string him;
    object ob,device;

    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place))
        place = environment(caster);
    him = caster->query_cap_name();
    ob = new("/d/magic/mon/priest_eelemental");
    elem = ob;
    ob->set_property("spell",TO);
    ob->set_property("spelled", ({TO}));
    ob->set_property("spell_creature", TO);
    device = new("/d/magic/obj/celemholder");
    tell_room(place,"%^BOLD%^%^GREEN%^The struggle seems to last an eternity, "
              +"but it ends with "+him+" over powering the prey and .....",caster);
    tell_object(caster,"%^BOLD%^%^GREEN%^You struggle with the being on the other end."
                +"Gradually you pull it closer to you. then suddenly......\n");
    tell_room(place,"%^BOLD%^%^YELLOW%^ CRRRRAAAAAACCCCCKKKKK!!!\n");
    tell_room(place,"%^BOLD%^%^GREEN%^Before you stands an earth elemental!");
    tell_object(caster,"%^BOLD%^%^GREEN%^Unable to resist your power the irate"
                +" being bows in acquiescence and awaits your command.\n");
    tell_room(place,"%^BOLD%^%^GREEN%^Unable to resist "+him+"'s power, the earth elemental "
              +" bows down to "+caster->query_objective()+"!",caster);
    device->set_elemental(ob);
    device->set_caster(caster);
    caster->add_follower(ob);
    device->move(caster);
    ob->move(place);
}

void dest_effect() {
    ::dest_effect();
    if(!objectp(elem)){
        TO->remove();
        return;
    }
    tell_room(environment(elem), "%^YELLOW%^The elemental bellows in rage, and then is no more.");
    elem->move("/d/shadowgate/void");
    elem->remove();
    TO->remove();
}

int help() {
    write(
@OLI
Spell  : Conjure Earth Elemental
Level  : 7th Level
Sphere : Elemental Earth
Deity  : Grumbar
Syntax : chant conjure earth elemental

This spell will summon an earth elemental for you to command. The
elemental will be under your control until you <dismiss> it or the
spell ends.
<command elemental to <action>> will command the summoned elemental.
OLI
);
    return 1;
}
