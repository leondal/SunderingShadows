//_summon_windghost.c - 8/05

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, v;
object caster, place, endplace;
object elem;

void create() {
    ::create();
    	set_spell_name("summon windghost");
	set_author("cythera");
    	set_spell_level(7);
    	set_spell_type("priest");
    	set_diety("shaundakul");
    	set_spell_sphere("summoning");
    	set_verbal_comp();
    	set_somatic_comp();
}

string query_cast_string() {
    	return "%^CYAN%^"+caster->QCN+" scans the sky as "+caster->QS+" "+
		"chants a prayer to Shaundakul.";
}

int preSpell() {
    if (present("celemdevicex999",caster)) {
        tell_object(caster,"You can only control one windghost at a time!\n");
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

    tell_room(place,"%^CYAN%^"+caster->QCN+" raises "+caster->QP+" "+
		"hands above "+caster->QP+" head.  "+caster->QCN+"'s chanting"+
		" grows louder and clearer.", caster);
    tell_object(caster,"%^CYAN%^You raise your hands above your head.  "+
		"Your chanting grows louder and clearer as you call out to Shaundakul.");
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

    tell_room(place,"%^CYAN%^The wind whips around "+caster->QCN+".  The"+
		" wind starts to form itself into a mass.",caster);
    tell_object(caster,"%^CYAN%^The wind whips around you and starts to"+
		" form itself into a mass.\n");
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

    ob = new("/d/magic/mon/windghost");
    elem = ob;
    ob->set_property("spelled", ({TO}));
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    device = new("/d/magic/obj/celemholder");
    tell_room(place,"%^CYAN%^The hazy mass of wind before "+caster->QCN+" "+
		"starts to take on a puple hue.",caster);
    tell_object(caster,"%^CYAN%^The hazy mass of wind before you starts"+
		" to take on a purple hue.\n");
    tell_room(place,"%^CYAN%^From within the haze a humanoid mass of "+
		"puple winds emerges.  The winds quickly fade away.");
    tell_object(caster,"%^CYAN%^You see a windghost emerge from the "+
		"purple haze!  The windghost stands before you, ready to"+
		" help you!\n");
    tell_room(place,"%^CYAN%^The humaniod mass of air stands before"+
		" "+caster->QCN+", fixing its pupiless white eyes on"+
		" "+caster->QO+"!",caster);
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
    tell_room(environment(elem), "%^CYAN%^The windghost merges with"+
		"the air, vanishing away.%^RESET%^");
    elem->move("/d/shadowgate/void");
    elem->remove();
    TO->remove();
}

int help() {
    write(
@HELP
Spell  : Summon Windghost
Level  : 7th Level
Sphere : Summoning
Deity  : Shaundakul
Syntax : chant summon windghost

This spell will summon windghost, loyal servants of Shaundakul, for you to command. The windghost will be completely under your control until the spell ends or you <dismiss> it.
<command windghost to <action>> will command the summoned windghost.
HELP
);
    return 1;
}
