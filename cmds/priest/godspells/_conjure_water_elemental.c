//_conjure_water_elemental.c
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
    set_spell_name("conjure water elemental");
    set_spell_level(6);
    set_spell_type("priest");
    set_diety("istishia");
    set_spell_sphere("elemental");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BOLD%^%^BLUE%^"+caster->query_cap_name()+" looks up at the sky and begins chanting to Istishia!";
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
    if (present("celemdevicex999",caster)) {
        tell_object(caster,"You can only control one elemental at a time!\n");
        return;
    }
    tell_room(place,"%^BOLD%^%^BLUE%^"+him+" raises "+caster->query_possessive()+" hands in what looks like agony."
              +" Mists swirl rapidly above "+caster->query_possessive()+" head. "
              +" You almost see a small hole in the fabric of the world in the middle.", caster);
    tell_object(caster,"%^BOLD%^%^BLUE%^You hands are lifted above you by a tremendous force."
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
                +"to leash a water elemental from its home plane.\n");
    call_out("step3",5);
}

void step3() {
    string him;
    object ob,device;
    int num;

    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    him = caster->query_cap_name();
    num = random(100);
    switch (num) {
    case 0..86:
        ob = new("/d/magic/mon/priest_welemental");
        device = new("/d/magic/obj/celemholder");
        tell_room(place,"%^BOLD%^%^BLUE%^The struggle seems to last an eternity, "
                  +"but it ends with "+him+" over powering the prey and .....",caster);
        tell_object(caster,"%^BOLD%^%^BLUE%^You struggle with the being on the other end."
                     +"Gradually you pull it closer to you. Then suddenly......\n");
        tell_room(place,"%^BOLD%^%^YELLOW%^ CRRRRAAAAAACCCCCKKKKK!!!\n");
        tell_room(place,"%^BOLD%^%^BLUE%^Before you stands a water elemental!");
        tell_object(caster,"%^BOLD%^%^BLUE%^Unable to resist your power the"
                    +" being bows in acquiescence and awaits your command.\n");
         tell_room(place,"%^BOLD%^%^BLUE%^Unable to resist "+him+"'s power, the water elemental"
                  +" bows down to "+caster->query_objective()+"!",caster);
        device->set_elemental(ob);  // this setting is different
        break;
    case 87..91:
        ob = new("/d/magic/obj/marid");
        device = new("/d/magic/obj/cgenieholder");
        tell_room(place,"%^BOLD%^%^BLUE%^The struggle seems to last an eternity, "
                  +"but it ends with "+him+" over powering the prey and .....",caster);
        tell_object(caster,"%^BOLD%^%^BLUE%^You struggle with the being on the other end."
                     +"Gradually you pull it closer to you. Then suddenly......\n");
        tell_room(place,"%^BOLD%^%^YELLOW%^ CRRRRAAAAAACCCCCKKKKK!!!\n");
        tell_room(place,"%^BOLD%^%^BLUE%^Before you stands a great marid!");
        tell_object(caster,"%^BOLD%^%^BLUE%^Unable to resist your power the"
                    +" being bows in acquiescence and awaits your command.\n");
        tell_room(place,"%^BOLD%^%^BLUE%^Unable to resist "+him+"'s power, the marid "
                  +" bows down to "+caster->query_objective()+"!",caster);
        device->set_genie(ob);
        break;
    case 92..99:
        ob = new("/d/magic/obj/varrdig");
        device = new("/d/magic/obj/celemholder");
        tell_room(place,"%^BOLD%^%^BLUE%^The struggle seems to last an eternity, "
                  +"but it ends with "+him+" over powering the prey and .....",caster);
        tell_object(caster,"%^BOLD%^%^BLUE%^You struggle with the being on the other end."
                     +"Gradually you pull it closer to you. Then suddenly......\n");
        tell_room(place,"%^BOLD%^%^YELLOW%^ CRRRRAAAAAACCCCCKKKKK!!!\n");
        tell_room(place,"%^BOLD%^%^BLUE%^Before you stands a varrdig!");
        tell_object(caster,"%^BOLD%^%^BLUE%^Unable to resist your power the"
                    +" being bows in acquiescence and awaits your command.\n");
        tell_room(place,"%^BOLD%^%^BLUE%^Unable to resist "+him+"'s power, the varrdig "
                  +" bows down to "+caster->query_objective()+"!",caster);
        device->set_elemental(ob);
        break;
    }
// moving all these to here so it's easier to be sure we're setting everything needed
    ob->set_property("spell",TO);
    ob->set_property("spelled", ({TO}) );
    ob->set_property("spell_creature", TO);
    device->set_caster(caster);
    caster->add_follower(ob);
    device->move(caster);
    ob->move(place);
    elem = ob;  // this was here already
}

void dest_effect() {
    ::dest_effect();
    if(!objectp(elem)){
        TO->remove();
        return;
    }

    tell_room(environment(elem), "%^BOLD%^%^RED%^The "+elem->query_short()+" disappears!");
    elem->move("/d/shadowgate/void");
    elem->remove();
    TO->remove();
}

int help() {
    write(
@OLI
Spell  : Conjure Water Elemental
Level  : 6th Level
Sphere : Elemental Water
Deity  : Istishia
Syntax : chant conjure water elemental

This spell has a 87% chance of summoning a water elemental,
9% chance of summoning a varrdig, and 4% chance of summoning
a marid for you to command. The creature is under your
complete control until you <dismiss> it or the spell ends.
<command elemental/genie to <action>> will command
the summoned creature.
OLI
);
    return 1;
}
