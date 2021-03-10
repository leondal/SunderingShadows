//_create_treant.c
// mon file moved to /d/magic/mon/ Ares/Styx 1/29/05

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, v;
object caster, place, endplace;
object treantob;

void create() {
    ::create();
    set_spell_name("create treant");
    set_spell_level(7);
    set_spell_type("priest");
    set_diety("mielikki");
    set_spell_sphere("forests");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BOLD%^%^GREEN%^"+caster->query_cap_name()+" calls for Mielikki's favor.";
}

int preSpell() {
    if (present("ctreedevicex999", caster)) {
        tell_object(caster,"You can only control one treant at a time!\n");
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
    tell_room(place,"%^BOLD%^%^GREEN%^"+him+" spreads "+caster->query_possessive()+" arms wide and concentrates on the ground before "+caster->query_subjective()+".",caster);
    tell_object(caster,"%^GREEN%^You stare intently at the ground before you and slowly see it begin to move.");
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
    tell_room(place,"%^BOLD%^You see something start to rise from the ground in front of "+him+".",caster);
    tell_object(caster,"%^BOLD%^Raw power runs through you as something rises from the ground before you.");
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
    ob = new("/d/magic/mon/treant");
    treantob = ob;
    ob->set_property("spell",TO);
    ob->set_property("spelled ", ({TO}));
    ob->set_property("spell_creature", TO);
    device = new("/d/magic/obj/ctreeholder");
    tell_room(place,"%^BOLD%^%^GREEN%^Before you stands a great treant!");
    tell_object(caster,"%^BOLD%^%^GREEN%^Unable to resist your power, the treant bows in acquiescence and awaits your command.\n");
    tell_room(place,"%^BOLD%^%^GREEN%^Unable to resist "+him+"'s power, the treant "
              +" bows down to "+caster->query_objective()+"!",caster);
    device->set_tree(ob);
    device->set_caster(caster);
    caster->add_follower(ob);
    device->move(caster);
    ob->move(place);
}

void dest_effect() {
    ::dest_effect();
    if(!objectp(treantob)){
        TO->remove();
        return;
    }
    tell_room(environment(treantob), "%^BOLD%^%^GREEN%^The treant stops suddenly then with a shriek of pain explodes into millions of splinters.");
    treantob->move("/d/shadowgate/void");
    treantob->remove();
    TO->remove();
}

int help() {
    write(
@OLI
Spell  : Create Treant
Level  : 7th Level
Sphere : Forests
Deity  : Mielikki
Syntax : chant create treant

This spell will summon a treant for you to command. The
treant will be completely under your control until the spell
ends or you <dismiss> it.
<command treant to <action>> will command the treant.
OLI
);
    return 1;
}

