// Invisibility - Coded by Vashkar@shadowgate
//altered for psions by ~Circe~ 7/24/05
#include <spell.h>
inherit SPELL;

object invisob;

void create() {
    ::create();
    set_spell_name("cloud mind");
    set_spell_level(([ "psion" : 2 ]));
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS cloud mind on TARGET");
    set_description("This power allows the psion to create a minor alteration in the minds of onlookers, so that they no "
"longer see the target.  The effect moves with the target, making him for all practical purposes invisible.  The power "
"will fail if the target becomes involved in a fight or decides to <appear>.  It may also wear off over time, though it "
"generally lasts quite awhile.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^MAGENTA%^"+caster->QCN+" pauses for a moment, standing "+
       "utterly still.";
}

void spell_effect(int prof) {
    if (!target)
        target=caster;

    if (interactive(caster)) {
        if (target==caster) {
            tell_object(caster,"%^BOLD%^%^MAGENTA%^You create a "+
               "concealing fog in the minds of those around you, "+
               "making them look straight through you!");
            tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" suddenly "+
               "vanishes from sight!",caster);
        } else {
            tell_object(caster,"%^BOLD%^%^MAGENTA%^You turn your attention "+
               "to "+target->QCN+", clouding minds so that "+target->QS+" "+
               "disappears from sight!");
            tell_object(target,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" turns "+
               ""+caster->QP+" attention to you, and you realize that "+
               "no one else can see you now!");
            tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" turns "+
               ""+caster->QP+" attention towards "+target->QCN+", who "+
               "suddenly vanishes from sight!",({caster, target}));
        }
    } else {
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" vanishes "+
           "from sight!");
    }
    call_out("targ_vanish",1, prof);
}

void targ_vanish(int prof) {
    if (!target || !present(target,environment(caster))) {
        tell_object(caster,"You look around, confused as to where "+
           "your target went, and shrug.");
        tell_room(caster->QCN+" looks around and shrugs in confusion.", caster);
        TO->remove();
        return;
    }
    if (target->query_invis()) {
        tell_object(caster,target->QCN+" is already invisible.");
        TO->remove();
        return;
    }
    if(target->query_property("visible")){
        tell_object(caster,"The power fails utterly on "+target->QCN+".");
        TO->remove();
        return;
    }
    spell_successful();
    invisob=new("/d/magic/obj/invisob.c");
    invisob->set_message("tpim","%^BOLD%^%^BLUE%^You feel secure, hidden from prying eyes.Type <appear> to become visible again.");
    invisob->set_message("tpeim","%^BOLD%^%^BLUE%^Your eyes glance over the spot where someone once stood.");
    invisob->set_message("tpdm","%^CYAN%^Suddenly, you are in full view of everyone around you, their befuddled minds made clear.");
    invisob->set_message("tpedm","%^CYAN%^Suddenly, someone appears in view.");
    invisob->set_property("spell",TO);
    invisob->set_property("spelled", ({TO}) );
    invisob->move_is_ok(1);
    invisob->move(target);
    invisob->set_prof(prof);
    invisob->move_is_ok(0);

    addSpellToCaster();
    return;
}

void dest_effect() {
    if (objectp(invisob)) {
        invisob->show_up();
    }
    if(objectp(target))   // added this check for objectp on target 11/3/02 *Styx*
	target->remove_property("visible");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
