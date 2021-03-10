//_creature_of_darkness.c - 10/05

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, v;
object caster, place, endplace;
object elem;

void create() {
    ::create();
    	set_spell_name("creature of darkness");
	set_author("cythera");
    	set_spell_level(7);
    	set_spell_type("priest");
    	set_diety("shar");
    	set_spell_sphere("summoning");
    	set_verbal_comp();
    	set_somatic_comp();
}

string query_cast_string() {
    	return "%^MAGENTA%^"+caster->QCN+" cast "+caster->QP+" gaze on a patch of darkness "+
		"as "+caster->QS+" starts to chant a soft spoken prayer.";
}

int preSpell() {
    if (present("celemdevicex999",caster)) {
        tell_object(caster,"You can only control one creature at a time!\n");
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

    if (objectp(place))
        place = environment(caster);
    him = caster->query_cap_name();

    tell_room(place,"%^MAGENTA%^"+caster->QCN+" curls "+caster->QP+" "+
		"fingers outwards, calling to the patch of darkness.", caster);
    tell_object(caster,"%^MAGENTA%^You call out to Shar as you stare at the patch of darkness.");
    call_out("next_step",5);
}

void next_step() {
    string him;

    if (!objectp(caster)){
        TO->remove();
        return;
    }

    if (objectp(place))
        place = environment(caster);
    him = caster->query_cap_name();

    tell_room(place,"%^MAGENTA%^The patch of darkness begins to boil "+
		"and churn as "+caster->QCN+" keeps on chanting.",caster);
    tell_object(caster,"%^MAGENTA%^You feel something within the darkness"+
		" answering your call, as it starts to churn and boil.\n");
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

    ob = new("/d/magic/mon/dark_creature");
    elem = ob;
    ob->set_property("spelled", ({TO}));
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    device = new("/d/magic/obj/celemholder");
    tell_room(place,"%^BOLD%^%^BLACK%^A humaniod shape rises up out "+
		"of the darkness, bowing before "+caster->QCN+".",caster);
    tell_object(caster,"%^BOLD%^%BLACK%^A humanoid shape rises up out of the darkness.\n");
    tell_object(caster,"%^MAGENTA%^The humanoid creature bows before you, ready to serve.\n");
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
    tell_room(environment(elem), "%^BOLD%^%^BLACK%^The creature merges with"+
		"a patch of darkness, vanishing away.%^RESET%^");
    elem->move("/d/shadowgate/void");
    elem->remove();
    TO->remove();
}

int help() {
    write(
@HELP
Spell  : Creature of Darkness
Level  : 7th Level
Sphere : Summoning
Deity  : Shar
Syntax : chant creature of darkness

Calling out to Shar, the priest is able to create a creature for a patch of darkness.  The creature remains under your control until the spell ends or you <dismiss> it.
<command creature to <action>> will command the creature of darkness.
HELP
);
    return 1;
}
